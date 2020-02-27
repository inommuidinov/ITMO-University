package expression.exceptions;

import expression.BinaryOperation;
import expression.CommonExpression;

public final class CheckedMultiply extends BinaryOperation {
    public CheckedMultiply(CommonExpression left, CommonExpression right) {
        super(left, right);
    }

    @Override
    public int getPriority() {
        return 1;
    }

    @Override
    public String getSymbol() {
        return "*";
    }

    @Override
    public int calculate(int x, int y) {
        if (x == 0 || y == 0)  return 0;
        if ((x > 0 && y > 0 && Integer.MAX_VALUE / x < y) || (x < 0 && y < 0 && Integer.MAX_VALUE / x > y)) {
            throw new OverflowException();
        }

        if ((x > 0 && y < 0 && Integer.MIN_VALUE / x > y) || (x < 0 && y > 0 && Integer.MIN_VALUE / y > x)) {
            throw new OverflowException();
        }
        int result = x * y;
        ///if (result / x != y || result / y != x)  throw new OverflowException();
        return x * y;
    }

    @Override
    public boolean needsExtraBrackets() {
        return false;
    }
}
