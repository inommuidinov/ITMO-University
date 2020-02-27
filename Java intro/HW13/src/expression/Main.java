package expression;

import expression.exceptions.ExpressionParser;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ExpressionParser parser = new ExpressionParser();
        Expression expression = parser.parse(scanner.nextLine());
        int ans = expression.evaluate(scanner.nextInt());
        System.out.println(ans);
        ///System.out.println(expression.evaluate(scanner.nextInt()));
    }
}