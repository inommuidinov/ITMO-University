package expression;

import java.util.Objects;

public class Const implements MainExpression {
    private int intValue;
    private double doubleValue;
    private boolean haveDouble;
    public Const(int intValue) {
        this.intValue = intValue;
        this.doubleValue = intValue;
        this.haveDouble = false;
    }
    public Const(double doubleValue) {
        this.intValue = (int) doubleValue;
        this.doubleValue = doubleValue;
        this.haveDouble = true;
    }
    @Override
    public String toString() {
        if (this.haveDouble) {
            return Double.toString(this.doubleValue);
        } else {
            return Integer.toString(this.intValue);
        }
    }
    @Override
    public int evaluate(int x) {
        return this.intValue;
    }
    @Override
    public double evaluate(double x) {
        return this.doubleValue;
    }
    @Override
    public boolean equals(Object exp) {
        if (exp instanceof Const) {
            return (this.intValue == ((Const) exp).intValue && this.doubleValue == ((Const) exp).doubleValue);
        } else {
            return false;
        }
    }
    @Override
    public int hashCode() {
        return intValue;
    }
}