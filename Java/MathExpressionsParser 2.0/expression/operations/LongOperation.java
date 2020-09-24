package expression.operations;

import expression.exceptions.*;

public class LongOperation implements Operation<Long> {
    public Long parseNumber(final String number) throws BadConstantException {
        try {
            return Long.parseLong(number);
        } catch (NumberFormatException NFM) {
            throw new BadConstantException();
        }
    }

    public Long add(final Long x, final Long y) {
        return x + y;
    }

    public Long sub(final Long x, final Long y) {
        return x - y;
    }

    public Long mul(final Long x, final Long y) {
        return x * y;
    }

    private void checkZero(final Long y, final String reason) throws BadOperationException {
        if (y == 0) {
            throw new BadOperationException(reason);
        }
    }

    public Long div(final Long x, final Long y) throws BadOperationException {
        checkZero(y, "Division by zero");
        return x / y;
    }

    public Long not(final Long x) {
        return -x;
    }

}