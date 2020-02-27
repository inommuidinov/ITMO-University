package HW10;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        final int n = in.nextInt();
        final int m = in.nextInt();
        final int k = in.nextInt();
        final int c = in.nextInt();
        ArrayList<Player> players = new ArrayList<>();
        //players.add(new HumanPlayer());
        players.add(new RandomPlayer());
         players.add(new RandomPlayer());
         players.add(new RandomPlayer());

        final Tourney tourney = new Tourney(new NMKBoard(n, m, k), players, c);
        tourney.begin();
        String result = tourney.result();
        System.out.println("Game result:\n" + result);
        in.close();
    }
}