package exp.parser;

public class StringSource implements Source {
    private final String str;
    private int pos;

    public StringSource(final String str) {
        this.str = str;
    }

    @Override
    public boolean hasNext() {
        return pos < str.length();
    }

    @Override
    public char next() {
        return str.charAt(pos++);
    }

    @Override
    public RuntimeException error(final String message) {
        return new RuntimeException(pos + ": " + message);
    }
}
