package exp;

import java.util.Objects;

public class Variable implements CommonExpression {
    private String name;
    public Variable(String name) {
        this.name = name;
    }
    @Override
    public int evaluate(int x) {
        return x;
    }
    @Override
    public int evaluate(int x, int y, int z) {
        int res = -1;
        switch (name) {
            case ("x"):
                res = x;
                break;
            case ("y"):
                res = y;
                break;
            case ("z"):
                res = z;
                break;
        }
        return res;
    }
    @Override
    public String toString() {
        return name;
    }
    @Override
    public String toMiniString() {
        return name;
    }
    @Override
    public boolean equals(Object exp) {
        if (exp != null && getClass() == exp.getClass()) {
            return Objects.equals(name, ((Variable) exp).name);
        }
        return false;
    }
    @Override
    public int hashCode() {
        return Objects.hash(name);
    }
}
