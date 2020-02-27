package expression;

public class Multiply extends AbstractOperator {
    public Multiply(MainExpression left, MainExpression right) {
        super(left, right);
    }
    @Override
    public int makeOperation(int left, int right) {
        return left * right;
    }
    @Override
    public double makeOperation(double left, double right) {
        return left * right;
    }
    @Override
    public String getOperator() {
        return "*";
    }
}