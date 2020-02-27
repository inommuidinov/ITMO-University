public class SumLong {
    public static void main(String[] args) {
        long sum = 0;
        for (int i = 0; i < args.length; i++) {
            int j = 0;
            while (j < args[i].length()) {
                while (j < args[i].length() && Character.isWhitespace(args[i].charAt(j))) {
                    j++;
                }
                if (j < args[i].length()) {
	                int to = j + 1;
	                while (to < args[i].length() && !Character.isWhitespace(args[i].charAt(to))) {
	                    to++;
	                }
	                sum += Long.parseLong(args[i].substring(j, to));
	                j = to;
            	}
            }
        }
        System.out.print(sum);
    }
}