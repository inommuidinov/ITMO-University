package exp;

public class RightShift extends AbstractOperator {
    public RightShift(CommonExpression left, CommonExpression right) {
        super(left, right);
        operator = ">>";
        priority = 0;
        order = true;
    }
    @Override
    public int makeOperation(int left, int right) {
        return left >> right;
    }
}
