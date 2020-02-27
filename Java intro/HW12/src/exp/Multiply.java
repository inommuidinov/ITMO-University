package exp;

public class Multiply extends AbstractOperator {
    public Multiply(CommonExpression left, CommonExpression right) {
        super(left, right);
        operator = "*";
        priority = 2;
        order = true;
    }
    @Override
    public int makeOperation(int left, int right) {
        return left * right;
    }
    @Override
    public String getOperator() {
        return "*";
    }
    @Override
    public boolean inOrder() {
        return true;
    }
    @Override
    public int getPriority() {
        return 2;
    }
}
