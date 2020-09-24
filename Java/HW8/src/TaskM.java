import java.io.*;
import java.util.*;

public class TaskM {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int TN = cin.nextInt();
        for (int k = 1; k <= TN; k++) {
            int n = cin.nextInt();
            int[] a = new int[n + 1];
            TreeMap<Integer, Integer> cnt = new TreeMap<>();
            for (int i = 1; i <= n; i++) {
                a[i] = cin.nextInt();
            }
            int ans = 0;
            for (int j = n; j >= 2; j--) {
                int cur = 0;
                for (int i = 1; i <= j - 1; i++) {
                    cur = 0;
                    if (cnt.containsKey(2 * a[j] - a[i])) {
                        cur = cnt.get(2 * a[j] - a[i]);
                    }
                    ans = ans + cur;
                }
                cur = 0;
                if (cnt.containsKey(a[j])) {
                    cur = cnt.get(a[j]);
                }
                cnt.put(a[j], cur + 1);
            }
            System.out.println(ans);
        }
    }
}
