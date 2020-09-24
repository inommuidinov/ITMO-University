import java.io.*;
import java.sql.SQLOutput;

interface Checker {
	boolean isWordCharacter(char c);
}

public class FastScanner {
	private Reader reader;
	private char[] buffer;
	private int pos = 0;
	private int sz = -1;

	public FastScanner(Reader r) {
		reader = r;
		buffer = new char[1000];
	}
	public FastScanner(InputStream in) {
		reader = new InputStreamReader(in);
		buffer = new char[1000];
	}
	public void close() {
		try {
			reader.close();
		} catch(IOException e) {
			System.out.println("Can't close reader !");
		}
	}
	private boolean readInput() throws IOException {
		do {
			sz = reader.read(buffer);
		} while (sz == 0);
		pos = 0;
		return sz >= 0;
	}
	public boolean hasInput() throws IOException {
		return !(sz <= 0 || pos >= sz) || readInput();
	}
	private void skipWhite(Checker check) throws IOException {
		while (hasInput() && !check.isWordCharacter(buffer[pos]) && buffer[pos] != '\n') {
			pos++;
		}
	}
	public void skipLine() throws IOException {
		while (hasInput()) {
			if (buffer[pos++] == '\n') {
				break;
			}
		}
	}
	public boolean isEndOfLine(Checker check) throws IOException {
		skipWhite(check);
		return !hasInput() || buffer[pos] == '\n';
	}
	public boolean isEmpty(Checker check) throws IOException {
		skipWhite(check);
		return !hasInput();
	}
	public boolean hasNext(Checker check) throws IOException {
		while (hasInput() && !check.isWordCharacter(buffer[pos])) {
			pos++;
		}
		return hasInput();
	}
	public String next(Checker check) throws IOException {
		skipWhite(check);
		StringBuilder res = new StringBuilder();
		while (hasInput() && check.isWordCharacter(buffer[pos])) {
			res.append(buffer[pos++]);
		}
		return res.toString();
	}
	public int nextInt(Checker check) throws IOException {
		return Integer.parseInt(next(check));
	}
}