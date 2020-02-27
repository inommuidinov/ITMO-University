package exp;

import java.util.Objects;

abstract class AbstractOperator implements CommonExpression {
    private CommonExpression left;
    private CommonExpression right;
    protected int priority;
    protected boolean order;
    protected String operator;
    public AbstractOperator(CommonExpression left, CommonExpression right) {
        this.left = left;
        this.right = right;
    }
    protected String getOperator() {
        return operator;
    }
    protected int getPriority() {
        return priority;
    }
    protected abstract int makeOperation(int left, int right);
    protected boolean inOrder() {
        return order;
    }

    @Override
    public int evaluate(int x) {
        int left = this.left.evaluate(x);
        int right = this.right.evaluate(x);
        return makeOperation(left, right);
    }
    @Override
    public int evaluate(int x, int y, int z) {
        int left = this.left.evaluate(x, y, z);
        int right = this.right.evaluate(x, y, z);
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

    private String getExpressionString(Expression exp, boolean brackets) {
        if (brackets) {
            StringBuilder stringBuilder = new StringBuilder("(");
            stringBuilder.append(exp.toMiniString());
            stringBuilder.append(")");
            return stringBuilder.toString();
        } else {
            return new StringBuilder(exp.toMiniString()).toString();
        }
    }

    private boolean checkPriority(Expression exp) {
        return ((exp instanceof AbstractOperator) && ((AbstractOperator) exp).getPriority() < this.getPriority());
    }

    private boolean needBracket(Expression exp) {
        if (exp instanceof AbstractOperator) {
            AbstractOperator cur = (AbstractOperator) exp;
            if (cur.inOrder() && cur.getPriority() <= this.getPriority()) {
                return true;
            }
            if (this.inOrder() && (cur.getPriority() <= this.getPriority())) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
    @Override
    public String toMiniString() {
        return getExpressionString(left, checkPriority(left)) + getOperator()
                + getExpressionString(right, checkPriority(right) || needBracket(right));
    }

    @Override
    public boolean equals(Object exp) {
        if (exp != null && exp.getClass() == getClass()) {
            AbstractOperator cur = (AbstractOperator) exp;
            return this.left.equals(cur.left) && right.equals(cur.right);
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
