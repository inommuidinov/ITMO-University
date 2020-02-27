package expression;

public class Variable implements MainExpression {
    private String name;
    public Variable(String name) {
        this.name = name;
    }
    @Override
    public String toString() {
        return name;
    }
    @Override
    public int evaluate(int x) {
        return x;
    }
    @Override
    public double evaluate(double x) {
        return x;
    }
    @Override
    public boolean equals(Object exp) {
        if (exp instanceof Variable) {
            return (this.name.equals(((Variable) exp).name));
        } else {
            return false;
        }
    }
    @Override
    public int hashCode() {
        return name.hashCode();
    }
}