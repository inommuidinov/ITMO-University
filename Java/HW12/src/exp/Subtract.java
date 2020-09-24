package exp;

public class Subtract extends AbstractOperator {
    public Subtract(CommonExpression left, CommonExpression right) {
        super(left, right);
        operator = "-";
        priority = 1;
        order = true;
    }
    @Override
    public int makeOperation(int left, int right) {
        return left - right;
    }
}
