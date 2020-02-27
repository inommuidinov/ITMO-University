package exp;

public class LeftShift extends AbstractOperator {
    public LeftShift(CommonExpression left, CommonExpression right) {
        super(left, right);
        operator = "<<";
        priority = 0;
        order = true;
    }
    @Override
    public int makeOperation(int left, int right) {
        return left << right;
    }
}
