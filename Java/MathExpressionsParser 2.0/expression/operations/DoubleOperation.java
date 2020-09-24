package expression.operations;

import expression.exceptions.*;

public class DoubleOperation implements Operation<Double> {
    public Double parseNumber(final String number) throws BadConstantException {
        try {
            return Double.parseDouble(number);
        } catch (NumberFormatException NFM) {
            throw new BadConstantException();
        }
    }

    public Double add(final Double x, final Double y) {
        return x + y;
    }

    public Double sub(final Double x, final Double y) {
        return x - y;
    }

    public Double mul(final Double x, final Double y) {
        return x * y;
    }

    public Double div(final Double x, final Double y) {
        return x / y;
    }

    public Double not(final Double x) {
        return -x;
    }

}