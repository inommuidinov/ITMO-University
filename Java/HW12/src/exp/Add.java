package exp;

public class Add extends AbstractOperator {
    public Add(CommonExpression left, CommonExpression right) {
        super(left, right);
        operator = "+";
        priority = 1;
        order = false;
    }

    @Override
    public int makeOperation(int left, int right) {
        return left + right;
    }
}
