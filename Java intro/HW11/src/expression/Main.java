package expression;

public class Main {
    public static void main(String[] args) {
        MainExpression test = new Subtract(
                new Multiply(
                        new Const(2),
                        new Variable("x")
                ),
                new Const(3)
        );
        System.out.println(test.evaluate(5));
        System.out.println(test.toString());
    }
}
