package exp.parser;

import exp.TripleExpression;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ExpressionParser expParser = new ExpressionParser();
        TripleExpression exp = expParser.parse(scanner.nextLine());
        System.out.println(exp);
    }
}