package expression.operations;

import expression.exceptions.*;

public class IntegerOperation implements Operation<Integer> {

    public Integer parseNumber(final String number) throws BadConstantException {
        try {
            return Integer.parseInt(number);
        } catch (NumberFormatException e) {
            throw new BadConstantException();
        }
    }

    private void checkAdd(final Integer x, final Integer y) throws ValueOverflowException {
        if (x > 0 && Integer.MAX_VALUE - x < y) {
            throw new ValueOverflowException();
        }
        if (x < 0 && Integer.MIN_VALUE - x > y) {
            throw new ValueOverflowException();
        }
    }

    public Integer add(final Integer x, final Integer y) throws ValueOverflowException {
        checkAdd(x, y);
        return x + y;
    }

    private void checkSub(final Integer x, final Integer y) throws ValueOverflowException {
        if (x >= 0 && y < 0 && x - Integer.MAX_VALUE > y) {
            throw new ValueOverflowException();
        }
        if (x <= 0 && y > 0 && Integer.MIN_VALUE - x > -y) {
            throw new ValueOverflowException();
        }
    }

    public Integer sub(final Integer x, final Integer y) throws ValueOverflowException {
        checkSub(x, y);
        return x - y;
    }

    private void checkMul(final Integer x, final Integer y) throws ValueOverflowException {
        if (x > 0 && y > 0 && Integer.MAX_VALUE / x < y) {
            throw new ValueOverflowException();
        }
        if (x > 0 && y < 0 && Integer.MIN_VALUE / x > y) {
            throw new ValueOverflowException();
        }
        if (x < 0 && y > 0 && Integer.MIN_VALUE / y > x) {
            throw new ValueOverflowException();
        }
        if (x < 0 && y < 0 && Integer.MAX_VALUE / x > y) {
            throw new ValueOverflowException();
        }
    }

    public Integer mul(final Integer x, final Integer y) throws ValueOverflowException {
        checkMul(x, y);

        return x * y;
    }

    private void checkDiv(final Integer x, final Integer y) throws ValueOverflowException {
        if (x == Integer.MIN_VALUE && y == -1) {
            throw new ValueOverflowException();
        }
    }

    private void checkZero(final int y, final String reason) throws BadOperationException {
        if (y == 0) {
            throw new BadOperationException(reason);
        }
    }

    public Integer div(final Integer x, final Integer y) throws BadOperationException, ValueOverflowException {
        checkZero(y, "Division by zero");
        checkDiv(x, y);
        return x / y;
    }

    private void checkNot(final Integer x) throws ValueOverflowException {
        if (x == Integer.MIN_VALUE) {
            throw new ValueOverflowException();
        }
    }

    public Integer not(final Integer x) throws ValueOverflowException {
        checkNot(x);
        return -x;
    }

}