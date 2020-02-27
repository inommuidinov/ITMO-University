package expression.exceptions;

import expression.BinaryOperation;
import expression.CommonExpression;
import expression.Const;
import expression.Variable;

import java.util.List;

public class ExpressionParser extends BaseParser implements Parser {
    private static final List< List<String> > PRIORITY_ORDER = List.of(List.of("pow2", "log2"), List.of("*", "/"), List.of("+", "-"));
    private static final int TOP = 2;
    private static final int LOW = -1;
    private static final List<Character> IMPORTANT = List.of('+', '-', '/', '*', '(', ')', '\0');
    @Override
    public CommonExpression parse(String expression) {
        setSource(new StringSource(expression));
        skipWhitespace();
        CommonExpression result = parse(TOP);
        if (ch != '\0') {
            throw new ExtraSymbolsException("Some correct symbols in need", getPosition());
        }
        return result;
    }

    private CommonExpression parse(int curLevel) {
        if (curLevel == LOW) {
            return getMinLevelExpression();
        }
        skipWhitespace();
        CommonExpression current = parse(curLevel - 1);
        boolean flag = true;
        while (flag) {
            flag = false;
            skipWhitespace();
            for (String operation: PRIORITY_ORDER.get(curLevel)) {
                if (test(operation)) {
                    current = getExpression(operation, current, parse(curLevel - 1));
                    flag = true;
                }
            }
        }
        return current;
    }

    private CommonExpression getMinLevelExpression() {
        skipWhitespace();
        if (test('-')) {
            if (isDigit()) {
                return getConst(true);
            } else {
                return new CheckedNegate(getMinLevelExpression());
            }
        } else if (isDigit()) {
            return getConst(false);
        } else if (test('(')) {
            CommonExpression result = parse(TOP);
            expect(')');
            return result;
        } else {
            StringBuilder builder = new StringBuilder();
            skipWhitespace();
            while (!IMPORTANT.contains(ch) && !Character.isWhitespace(ch)) {
                builder.append(ch);
                nextChar();
            }
            skipWhitespace();

            String value = builder.toString();
            if (value.equals("log2"))
                return new CheckedLog2(getMinLevelExpression());
            else if (value.equals("pow2"))
                return new CheckedPow2(getMinLevelExpression());
            else if (value.equals("x") || value.equals("y") || value.equals("z"))
                return new Variable(value);
            else if (value.equals(""))
                throw new NotFoundException("variable, found nothing", getPosition() - value.length());
            else
                throw new InvalidVariableException(value, getPosition() - value.length());
        }
    }

    private Const getConst(boolean isNegative) {
        StringBuilder stringBuilder = new StringBuilder();
        if (isNegative)
            stringBuilder.append("-");
        while (isDigit()) {
            stringBuilder.append(ch);
            nextChar();
        }
        String value = stringBuilder.toString();
        try {
            return new Const(Integer.parseInt(value));
        } catch (NumberFormatException e) {
            throw new InvalidConstException(value, getPosition());
        }
    }

    private BinaryOperation getExpression(String lastOperation, CommonExpression left, CommonExpression right) {
        if (lastOperation.equals("+")) return new CheckedAdd(left, right);
        else if (lastOperation.equals("-")) return new CheckedSubtract(left, right);
        else if (lastOperation.equals("*")) return new CheckedMultiply(left, right);
        else if (lastOperation.equals("/")) return new CheckedDivide(left, right);
        else throw new AssertionError("Unsupported operation " + lastOperation);

    }
}
