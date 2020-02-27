package exp.parser;

public class BaseParser {
    private Source src;
    protected char ch;

    protected void setSource(Source src) {
        this.src = src;
    }

    protected void nextChar() {
        ch = '\0';
        if (src.hasNext()) {
            ch = src.next();
            /// System.out.println(c);
        }
    }
    protected boolean test(char like) {
        if (ch == like) {
            nextChar();
            return true;
        }
        return false;
    }

    protected void expect(final char c) {
        if (ch != c) {
            throw error("Expected '" + c + "', found '" + ch + "'");
        }
        nextChar();
    }
    protected void expect(final String str) {
        for (char ch: str.toCharArray()) {
            expect(ch);
        }
    }

    protected boolean assertCheck(final char left, final char right) {
        return ch >= left && ch <= right;
    }

    protected RuntimeException error(final String message) {
        return src.error(message);
    }
}
