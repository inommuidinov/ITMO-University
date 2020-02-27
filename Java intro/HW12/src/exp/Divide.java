package exp;

public class Divide extends AbstractOperator {
    public Divide(CommonExpression left, CommonExpression right) {
        super(left, right);
        operator = "/";
        priority = 2;
        order = true;
    }
    @Override
    public int makeOperation(int left, int right) {
        return left / right;
    }
}
