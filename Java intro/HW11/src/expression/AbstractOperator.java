package expression;

import java.util.Objects;

public abstract class AbstractOperator implements MainExpression {
    private MainExpression left, right;
    public AbstractOperator(MainExpression left, MainExpression right) {
        this.left = left;
        this.right = right;
    }
    protected abstract int makeOperation(int left, int right);
    protected abstract double makeOperation(double left, double right);
    protected abstract String getOperator();
    public int evaluate(int x) {
        int left = this.left.evaluate(x);
        int right = this.right.evaluate(x);
        return makeOperation(left, right);
    }
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("(");
        stringBuilder.append(left.toString());
        stringBuilder.append(" ");
        stringBuilder.append(this.getOperator());
        stringBuilder.append(" ");
        stringBuilder.append(right.toString());
        stringBuilder.append(")");
        return stringBuilder.toString();
    }
    public double evaluate(double x) {
        double left = this.left.evaluate(x);
        double right = this.right.evaluate(x);
        return makeOperation(left, right);
    }
    @Override
    public boolean equals(Object exp) {
        if (exp != null && exp.getClass() == getClass()) {
            return ((AbstractOperator) exp).left.equals(this.left) && ((AbstractOperator) exp).right.equals(this.right)
                    && ((AbstractOperator) exp).getOperator().equals(this.getOperator());
        } else {
            return false;
        }
    }
    @Override
    public int hashCode() {
        int left = this.left.hashCode();
        int right = this.right.hashCode();
        return Objects.hash(left, right, this.getOperator());
    }
}
