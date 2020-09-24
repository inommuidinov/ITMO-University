package expression;

import expression.exceptions.*;
import expression.expressions.*;
import expression.operations.*;
import expression.parser.*;

import java.util.HashMap;

public class GenericTabulator implements Tabulator {
    private final static HashMap<String, Operation<?>> MODES = new HashMap<>();

    static {
        MODES.put("i", new IntegerOperation());
        MODES.put("bi", new BigIntegerOperation());
        MODES.put("d", new DoubleOperation());
        MODES.put("l", new LongOperation());
        MODES.put("s", new ShortOperation());
    }

    public Object[][][] tabulate(String mode, String expression, int x1, int x2, int y1, int y2, int z1, int z2)
            throws UnknownModeException {
        return makeTable(getOperation(mode), expression, x1, x2, y1, y2, z1, z2);
    }

    private Operation<?> getOperation(final String mode) throws UnknownModeException {
        Operation<?> result = MODES.get(mode);
        if (result == null) {
            throw new UnknownModeException(mode);
        }
        return result;
    }

    private <T> Object[][][] makeTable(Operation<T> op, String expression, int x1, int x2, int y1, int y2, int z1,
            int z2) {
        Object[][][] res = new Object[x2 - x1 + 1][y2 - y1 + 1][z2 - z1 + 1];
        Parser<T> parser = new ExpressionParser<>(op);
        TripleExpression<T> exp;
        try {
            exp = parser.parse(expression);
        } catch (ParsingException e) {
            return res;
        }
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                for (int k = z1; k <= z2; k++) {
                    try {
                        res[i - x1][j - y1][k - z1] = exp.evaluate(op.parseNumber(Integer.toString(i)),
                                op.parseNumber(Integer.toString(j)), op.parseNumber(Integer.toString(k)));
                    } catch (ParsingException | CalculatingException e) {
                        res[i - x1][j - y1][k - z1] = null;
                    }
                }
            }
        }
        return res;
    }
}