import java.io.*;
import java.util.*;

public class TaskJ {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        String cur = cin.nextLine();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            cur = cin.nextLine();
            for (int j = 0; j < cur.length(); j++) {
                a[i][j] = cur.charAt(j) - 48;
            }
        }
        /*System.out.println();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j]);
            }
            System.out.println();
        }
        System.out.println();*/
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    for (int k = 0; k < n; k++) {
                        a[i][k] = (a[i][k] - a[j][k] + 10) % 10;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j]);
            }
            System.out.println();
        }
    }
}
