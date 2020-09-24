package expression.exceptions;

import expression.CommonExpression;
import expression.UnaryOperation;

public final class CheckedNegate extends UnaryOperation {

    public CheckedNegate(CommonExpression inner) {
        super(inner);
    }

    @Override
    public int calculate(int x) {
        if (x > 0 && Integer.MIN_VALUE + x > 0 || x < 0 && Integer.MAX_VALUE + x < 0) {
            throw new OverflowException();
        }
        return -x;
    }

    @Override
    public String getSymbol() {
        return "-";
    }
}
