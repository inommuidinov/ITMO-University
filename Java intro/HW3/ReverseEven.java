import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class ReverseEven {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		List<List<Integer>> data = new ArrayList<> ();

		while (in.hasNextLine()) {
			String currentLine = in.nextLine();
			Scanner currentScanner = new Scanner(currentLine);

			List<Integer> currentList = new ArrayList<> ();
			while (currentScanner.hasNextInt()) {
				int currentNumber = currentScanner.nextInt();
				if (currentNumber % 2 == 0) {
					currentList.add(currentNumber);
				}
			}

			data.add(currentList);
		}

		for (int i = data.size() - 1; i >= 0; i--) {
			for (int j = data.get(i).size() - 1; j >= 0; j--) {
				System.out.print(data.get(i).get(j) + " ");
			}
			System.out.println();
		}
	}
}
