package expression.expressions;

import expression.exceptions.*;
import expression.operations.*;

public abstract class AbstractUnaryOperator<T> implements TripleExpression<T> {
    private final TripleExpression<T> a;
    protected final Operation<T> op;

    protected AbstractUnaryOperator(final TripleExpression<T> x, final Operation<T> y) {
        a = x;
        op = y;
    }

    protected abstract T apply(final T x) throws CalculatingException;

    public T evaluate(final T x, final T y, final T z) throws CalculatingException {
        return apply(a.evaluate(x, y, z));
    }
}
