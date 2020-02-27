package exp;

import java.awt.*;
import java.util.Objects;

public class Const implements CommonExpression {
    private int value;
    public Const(int value) {
        this.value = value;
    }

    public boolean isNegative() {
        return value < 0;
    }
    @Override
    public int evaluate(int x) {
        return this.value;
    }

    @Override
    public int evaluate(int x, int y, int z) {
        return this.value;
    }

    @Override
    public String toString() {
        return Integer.toString(this.value);
    }

    @Override
    public String toMiniString() {
        return Integer.toString(value);
    }

    @Override
    public boolean equals(Object exp) {
        if (exp == null || getClass() != exp.getClass()) {
            return false;
        }
        return value == ((Const) exp).value;
    }

    @Override
    public int hashCode() {
        return Objects.hash(value);
    }
}
