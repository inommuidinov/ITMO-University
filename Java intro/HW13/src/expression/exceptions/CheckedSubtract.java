package expression.exceptions;

import expression.BinaryOperation;
import expression.CommonExpression;

public final class CheckedSubtract extends BinaryOperation {
    public CheckedSubtract(CommonExpression left, CommonExpression right) {
        super(left, right);
    }

    @Override
    public int getPriority() {
        return 2;
    }

    @Override
    public String getSymbol() {
        return "-";
    }

    @Override
    public int calculate(int x, int y) {
        if (y > 0 && Integer.MIN_VALUE + y > x || y < 0 && Integer.MAX_VALUE + y < x) {
            /// System.out.println("sub " + x + " " + y);
            throw new OverflowException();
        }
        return x - y;
    }

    @Override
    public boolean needsExtraBrackets() {
        return true;
    }
}
