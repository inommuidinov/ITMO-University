package exp.parser;

import exp.*;

import java.util.Map;

public class ExpressionParser extends BaseParser implements Parser {
    private String lastOperator = ")";
    private static final int highLevel = 3;
    private static final int lowLevel = 0;
    private static final Map<String, Integer> priorities = Map.of(
            "+", 2,
            "-", 2,
            "*", 1,
            "/", 1,
            "<<", 3,
            ">>", 3,
            ")", highLevel + 1
    );
    private static final Map<Character, String> firstCharToOperator = Map.of(
            '+', "+",
            '-', "-",
            '*', "*",
            '/', "/",
            ')', ")",
            '<', "<<",
            '>', ">>"
    );

    @Override
    public TripleExpression parse(String exp) {
        setSource(new StringSource(format(exp)));
        nextChar();
        return parseLevel(highLevel);
    }

    private CommonExpression parseLevel(int level) {
        if (level == lowLevel) {
            return getPrimeExpression();
        }
        CommonExpression exp = parseLevel(level - 1);
        while (priorities.get(lastOperator) == level) {
            exp = makeExpression(lastOperator, exp, parseLevel(level - 1));
        }
        if (level == highLevel) {
            testOperator();
        }
        return exp;
    }

    private CommonExpression getPrimeExpression() {
        if (test('-')) {
            if (assertCheck('0', '9')) {
                return getConstExpression(true);
            } else {
                return Negative.getNegativeExpression(parseLevel(0));
            }
        } else if (test('(')) {
            return parseLevel(highLevel);
        } else if (assertCheck('0', '9')) {
            return getConstExpression(false);
        } else {
            return getVariableExpression();
        }
    }

    private CommonExpression getVariableExpression() {
        StringBuilder stringBuilder = new StringBuilder();
        while (!testOperator()) {
            stringBuilder.append(ch);
            nextChar();
        }
        return new Variable(stringBuilder.toString());
    }

    private CommonExpression getConstExpression(boolean isNegative) {
        StringBuilder stringBuilder = new StringBuilder(isNegative ? "-" : "");
        while (assertCheck('0', '9')) {
            stringBuilder.append(ch);
            nextChar();
        }
        testOperator();
        try {
            return new Const(Integer.parseInt(stringBuilder.toString()));
        } catch (NumberFormatException e) {
            throw error("Illegal variable :" + stringBuilder.toString());
        }
    }

    private boolean testOperator() {
        if (!firstCharToOperator.containsKey(ch)) {
            return false;
        }
        getOperator();
        return true;
    }

    private void getOperator() {
        String operator = firstCharToOperator.get(ch);
        expect(operator);
        lastOperator = operator;
    }
    private CommonExpression makeExpression(String operator, CommonExpression left, CommonExpression right) {
        if (operator.equals("+")) {
            return new Add(left, right);
        }
        if (operator.equals("-")) {
            return new Subtract(left, right);
        }
        if (operator.equals("*")) {
            return new Multiply(left, right);
        }
        if (operator.equals("/")) {
            return new Divide(left, right);
        }
        if (operator.equals("<<")) {
            return new LeftShift(left, right);
        }
        if (operator.equals(">>")) {
            return new RightShift(left, right);
        }
        throw error("Unsupported operator: " + operator);
    }
    private String format(String str) {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isWhitespace(str.charAt(i))) {
                stringBuilder.append(str.charAt(i));
            }
        }
        return stringBuilder.toString() + ')';
    }
}