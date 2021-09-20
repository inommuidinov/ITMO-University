package expression.expressions;

import expression.exceptions.*;
import expression.operations.*;

public abstract class AbstractBinaryOperator<T> implements TripleExpression<T> {
    private final TripleExpression<T> a;
    private final TripleExpression<T> b;
    protected final Operation<T> op;

    protected AbstractBinaryOperator(final TripleExpression<T> x, final TripleExpression<T> y, final Operation<T> z) {
        a = x;
        b = y;
        op = z;
    }

    protected abstract T apply(final T x, final T y) throws CalculatingException;

    public T evaluate(final T x, final T y, final T z) throws CalculatingException {
        return apply(a.evaluate(x, y, z), b.evaluate(x, y, z));
    }

}