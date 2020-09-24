import java.io.*;
import java.util.*;

public class TaskA {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();
        int b = cin.nextInt();
        int n = cin.nextInt();
        int cur = (n - b) / (b - a);
        if ((n - b) % (b - a) > 0) {
            cur++;
        }
        int ans = 2 * cur + 1;
        System.out.println(ans);
        cin.close();
    }
}
