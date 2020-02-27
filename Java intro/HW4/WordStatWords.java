import java.nio.charset.StandardCharsets;
import java.util.*;
import java.io.*;
import java.util.Scanner;
import java.util.Map;
import java.io.UnsupportedEncodingException;

public class WordStatWords {
	public static void main(String[] args) {
		if (args.length == 2) {
			String inputFileName = args[0];
			String outputFileName = args[1];
			Map<String, Integer> count = new TreeMap<> ();
			Scanner in = null;
			try {
				in = new Scanner(new File(inputFileName), StandardCharsets.UTF_8);
				while (in.hasNext()) {
					// Regular expression was written based on https://www.regular-expressions.info/unicode.html
					String[] currentTokens = in.next().split("[^\\p{Pd}\\p{L}']");
					for (String currentWord: currentTokens) {
						currentWord = currentWord.toLowerCase();
						if (currentWord.isEmpty()) {
							continue;
						}
						
						if (count.containsKey(currentWord)) {
							count.put(currentWord, count.get(currentWord) + 1);
						} else {
							count.put(currentWord, 1);
						}
					}
				}
				try {
	        		PrintWriter output = new PrintWriter(new OutputStreamWriter(
	                	    new FileOutputStream(outputFileName), StandardCharsets.UTF_8));
					for (Map.Entry<String, Integer> entry: count.entrySet()) {
						String key = entry.getKey();
						int cnt = entry.getValue();
						output.println(key + " " + cnt);
					}
					output.close();
		        } catch (FileNotFoundException e) {
		                System.out.println("Some error ocured while opening or writing to output-file!");
		        }
			} catch (FileNotFoundException e) {
                System.out.println("Some error ocured while opening input-file!");
			} catch (IllegalArgumentException ex) {
                System.out.println("The encoding You need is unsupported!");
            } catch (IOException e) {
				System.out.println("Something is goes wrong with input-file!");
	        } finally {
	        	in.close();
	        }
	         
	    } else {
	    	System.out.println("Please, write the names of 2 files. Write them in this format:\n" +
                    "Usage: <inputFileName.format> <outputFileName.format>");
	    }
	}
}
