package expression.operations;

import expression.exceptions.*;

public class ShortOperation implements Operation<Short> {
    public Short parseNumber(final String number) throws BadConstantException {
        /*
         * try { return Short.parseShort(number); } catch (NumberFormatException NFM) {
         * throw new BadConstantException(); }
         */
        return (short) Integer.parseInt(number);
    }

    public Short add(final Short x, final Short y) {
        return (short) (x + y);
    }

    public Short sub(final Short x, final Short y) {
        return (short) (x - y);
    }

    public Short mul(final Short x, final Short y) {
        return (short) (x * y);
    }

    private void checkZero(final Short y, final String reason) throws BadOperationException {
        if (y == 0) {
            throw new BadOperationException(reason);
        }
    }

    public Short div(final Short x, final Short y) throws BadOperationException {
        checkZero(y, "Division by zero");
        return (short) (x / y);
    }

    public Short not(final Short x) {
        return (short) (-x);
    }

}