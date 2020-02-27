package expression.exceptions;

public class ExtraSymbolsException extends ParsingException {
    public ExtraSymbolsException(String str, int pos) {
        super(str, pos);
    }
}
