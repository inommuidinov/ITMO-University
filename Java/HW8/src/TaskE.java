import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Stream;
import java.util.stream.Collectors;

public class TaskE {
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
        int n;
        int m;
        int[] length;
        int[] parent;
        List<List<Integer>> verr;

        private void dfs(int x, int pr, int dep) {
            length[x] = dep;
            parent[x] = pr;
            for (int i = 0; i < verr.get(x).size(); i++) {
                int to = verr.get(x).get(i);
                if (to != pr) {
                    dfs(to, x, dep + 1);
                }
            }
        }

        void solve(InputReader cin, PrintWriter out) {
            n = cin.nextInt();
            m = cin.nextInt();
            verr = Stream.<List<Integer>>generate(ArrayList::new).limit(n + 1).collect(Collectors.toList());
            for (int i = 0; i < n - 1; i++) {
                int x, y;
                x = cin.nextInt();
                y = cin.nextInt();
                verr.get(x).add(y);
                verr.get(y).add(x);
            }
            int[] team = new int[n + 2];
            for (int i = 1; i <= m; i++) {
                team[i] = cin.nextInt();
            }
            parent = new int[n + 2];
            length = new int[n + 2];
            dfs(team[1], team[1], 0);
            int depth = -1, v = 0;
            for (int i = 1; i <= m; i++) {
                if (depth < length[team[i]]) {
                    depth = length[team[i]];
                    v = team[i];
                }
                // depth = Math.max(depth, length[team[i]]);
            }
            if (depth % 2 != 0) {
                out.println("NO");
                return;
            }
            for (int i = 1; i <= depth / 2; i++) {
                v = parent[v];
            }
            dfs(v, v, 0);
            for (int i = 1; i <= m; i++) {
                if (length[team[i]] != depth / 2) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES\n" + v);
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