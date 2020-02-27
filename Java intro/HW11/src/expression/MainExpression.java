package expression;

public interface MainExpression extends Expression, DoubleExpression {
    public String toString();
    public int evaluate(int x);
    public double evaluate(double x);
}
