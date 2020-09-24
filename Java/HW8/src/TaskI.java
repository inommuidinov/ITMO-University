import java.io.*;
import java.util.*;

public class TaskI {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int xl = 0, xr = 0, yl = 0, yr = 0;
        for (int i = 1; i <= n; i++) {
            int x = cin.nextInt();
            int y = cin.nextInt();
            int h = cin.nextInt();
            if (i == 1) {
                xl = x - h; xr = x + h;
                yl = y - h; yr = y + h;
            } else {
                xl = Math.min(xl, x - h); xr = Math.max(xr, x + h);
                yl = Math.min(yl, y - h); yr = Math.max(yr, y + h);
            }
        }
        int mx = Math.max(xr - xl, yr - yl);
        int h = mx / 2 + mx % 2;
        System.out.println((xl + xr) / 2 + " " +  (yl + yr) /  2 + " " + h);
    }
}
