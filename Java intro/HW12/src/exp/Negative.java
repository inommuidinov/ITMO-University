package exp;

public class Negative implements CommonExpression {
    private CommonExpression exp;
    public static CommonExpression getNegativeExpression(CommonExpression exp) {
        if (exp instanceof Const) {
            return new Const(-exp.evaluate(0));
        }
        if (exp instanceof Negative) {
            return ((Negative) exp).exp;
        }
        return new Negative(exp);
    }

    private Negative(CommonExpression exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("-(");
        stringBuilder.append(exp.toString());
        stringBuilder.append(")");
        return stringBuilder.toString();
    }

    @Override
    public String toMiniString() {
        if (exp instanceof AbstractOperator) {
            StringBuilder stringBuilder = new StringBuilder("-(");
            stringBuilder.append(exp.toMiniString());
            stringBuilder.append(")");
            return stringBuilder.toString();
        } else {
            return new StringBuilder(exp.toString()).toString();
        }
    }

    @Override
    public int evaluate(int x) {
        int cur = this.exp.evaluate(x);
        return -cur;
    }
    @Override
    public int evaluate(int x, int y, int z) {
        int cur = this.exp.evaluate(x, y, z);
        return -cur;
    }
}
