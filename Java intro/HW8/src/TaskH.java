import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Map;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class TaskH {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader cin = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(cin, out);
        out.close();
    }

    static class Solver {
        void solve(InputReader cin, PrintWriter out) {
            int n;
            n = cin.nextInt();
            int[] a = new int[n + 1];
            int[] p = new int[n + 1];
            a[0] = p[0] = 0;
            int max = 0;
            for (int i = 1; i <= n; i++) {
                a[i] = cin.nextInt();
                max = Math.max(max, a[i]);
                p[i] = p[i - 1] + a[i];
            }
            Map<Integer, Integer> us = new TreeMap<>();
            int TN = cin.nextInt();
            for (int t = 1; t <= TN; t++) {
                int cur = cin.nextInt();
                if (us.containsKey(cur)) {
                    out.println(us.get(cur));
                } else {
                    if (cur < max) {
                        out.println("Impossible");
                    } else {
                        int ans = 0;
                        for (int pos = 1; pos <= n;) {
                            int l = pos, r = n + 1;
                            while (l + 1 < r) {
                                int mid = (l + r) / 2;
                                int s = p[mid] - p[pos - 1];
                                if (s <= cur) {
                                    l = mid;
                                } else {
                                    r = mid;
                                }
                            }
                            pos = r;
                            ans++;
                        }
                        us.put(cur, ans);
                        out.println(ans);
                    }
                }
            }
        }
    }
    static class InputReader {
        final BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        public void close() {
        }
    }
}