package expression.exceptions;

public class InvalidArgumentException extends ExpressionException {
    public InvalidArgumentException(String arguments) {
        super("Invalid Argument " + arguments);
    }
}
