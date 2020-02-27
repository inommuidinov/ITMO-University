import java.io.*;
import java.util.*;
import java.nio.charset.StandardCharsets;

class MyChecker implements Checker {
	public boolean isWordCharacter(char c) {
		return Character.getType(c) == Character.DASH_PUNCTUATION 
		|| c == '\'' || Character.isLetter(c);
	}
}

public class WordStatLineIndex {
	private static Checker check = new MyChecker();
	
	public static void main(String[] args) {
		if (args.length != 2) {
			System.out.println("Please, write correct filenames :|");
			return;
		}

		Map<String, ArrayList<String>> map = new TreeMap<>();
		try (FastScanner in = new FastScanner(args[0], check)) {
			int cnt = 1;
			while (in.hasNext()) {
				try {
					ArrayList<String> a = in.getWordInLine();
					for (int i = 0; i < a.size(); i++) {
						String cur = a.get(i).toLowerCase();
						if (cur.length() > 0) {
							ArrayList<String> tmp = map.getOrDefault(cur, new ArrayList<>());
							tmp.add(cnt + ":" + (i + 1));
							map.put(cur, tmp);
						}
					}
					cnt++;
				} catch (IOException e) {
					System.out.println("Wrong data !");
				}
			}
			try (Writer writer = new BufferedWriter(
					new OutputStreamWriter(new FileOutputStream(args[1]), StandardCharsets.UTF_8))) {
				for (Map.Entry<String, ArrayList<String>> it : map.entrySet()) {
					writer.write(it.getKey() + " " + it.getValue().size());
					for (String i: it.getValue()) {
						writer.write(" " + i);
					}
					writer.write("\n");
				}
			} catch (FileNotFoundException e) {
				System.out.println("Can't create an output file ! :(" + e.getMessage());
			} catch (IOException e) {
				System.out.println("Output error: " + e.getMessage());
			}
		} catch (FileNotFoundException e) {
			System.out.println("Input file not found: " + e.getMessage());
			return;
		} catch (IOException e) {
			System.out.println("Input error: " + e.getMessage());
			return;
		}
	}
}