import java.io.*;
import java.util.*;

class MyTriple {
	long sum;
	int pos;
	String line;
	public MyTriple(long sum, int pos, String line) {
		this.sum = sum;
		this.pos = pos;
		this.line = line;
	}
}

class MyChecker implements Checker {
	public boolean isWordCharacter(char c) {
		return !Character.isWhitespace(c);
	}
}

public class ReverseSort {
	
	private static MyChecker ch = new MyChecker();
	
	public static void main(String[] args) {
		int total = 0;
		MyTriple[] ans = new MyTriple[1];
		FastScanner in = new FastScanner(System.in);
		try {
			while (!in.isEmpty(ch)) {
				int[] row = new int[1];
				int size = 0;
				long sum = 0;
				while (!in.isEndOfLine(ch)) {
					int cur = in.nextInt(ch);
					if (size == row.length) {
						row = Arrays.copyOf(row, size * 2);
					}
					row[size++] = cur; sum += cur;
				}
				in.skipLine();
				row = Arrays.copyOf(row, size);
				Arrays.sort(row);
				for (int i = 0; i < size / 2; i++) {
					int tmp = row[i];
					row[i] = row[size - i - 1];
					row[size - i - 1] = tmp;
				}
				StringBuilder res = new StringBuilder();
				for (int i: row) {
					res.append(i).append(" ");
				}
				res.append("\n");
				if (total == ans.length) {
					ans = Arrays.copyOf(ans, total * 2);
				}
				ans[total++] = new MyTriple(sum, total, res.toString());
			}

		} catch(IOException e) {
			System.out.println("Input Error: " + e.getMessage());
		} finally {
			in.close();
		}
		ans = Arrays.copyOf(ans, total);
		Arrays.sort(ans, new Comparator<>() {
			public int compare(MyTriple x, MyTriple y) {
				if (x.sum > y.sum) {
					return -1;
				} else if (x.sum == y.sum) {
					return Integer.compare(y.pos, x.pos);
				} else {
					return 1;
				}
			}
		});
		for (int i = 0; i < total; i++) {
			System.out.print(ans[i].line);
		}
	}
}