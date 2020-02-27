package search;


public class BinarySearchMissing {
    public static int iterativeBinarySearch(int x, int a[]) {
        int l = 0, r = a.length;
        while (l < r) {
            int m = (l + r) / 2;

            if (x >= a[m]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return (r < a.length) && (a[r] == x) ? r : (-r - 1);
    }
    public static int recursiveBinarySearch(int x, int a[]) {
        return recursiveBinarySearch(x, a, 0, a.length);
    }

    public static int recursiveBinarySearch(int x, int a[], int l, int r) {
        if (l >= r) {
            return (r < a.length) && (a[r] == x) ? r : (-r - 1);
        }
        int m = (l + r) / 2;
        if (x >= a[m]) {
            return recursiveBinarySearch(x, a, l, m);
        } else {
            return recursiveBinarySearch(x, a, m + 1, r);
        }
    }

    public static void main(String[] args) {
        if (args.length != 0) {
            int x = Integer.parseInt(args[0]);
            int[] a = new int[args.length - 1];
            for (int i = 1; i < args.length; i++) {
                a[i - 1] = Integer.parseInt(args[i]);
            }
            int iterativeResult = iterativeBinarySearch(x, a);
            int recursiveResult = recursiveBinarySearch(x, a);
            System.out.println(iterativeResult == recursiveResult ? iterativeResult : "ERROR!!!");
        } else {
            System.out.println("Please, write at least one element!");
        }

    }
}