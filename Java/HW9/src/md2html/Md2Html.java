package md2html;

import java.io.*;

public class Md2Html {

    public static void main(String[] args) {
        StringBuilder res = new StringBuilder();
        try {
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(
                            new FileInputStream(args[0]),
                            "utf-8"
                    ),
                    1024
            );
            try {
                String s = "";
                StringBuilder temp = new StringBuilder();
                while (s != null && (s = in.readLine()) != null) {
                    while (s != null && !s.equals("")) {
                        temp.append(s);
                        temp.append('\n');
                        s = in.readLine();
                    }
                    if (temp.length() != 0) {
                        temp.setLength(temp.length() - 1);
                        new BlockParser(temp).toHtml(res);
                        res.append('\n');
                        temp = new StringBuilder();
                    }
                }

            } finally {
                in.close();
            }
            BufferedWriter out = new BufferedWriter(
                    new OutputStreamWriter(
                            new FileOutputStream(args[1]),
                            "utf-8"
                    ),
                    1024
            );
            try {
                out.write(res.toString());
            } catch (FileNotFoundException e) {
                System.out.println(" File Out not found! " + e.getMessage());
            } finally {
                out.close();
            }
        } catch (FileNotFoundException e) {
            System.out.println(" File In not found! " + e.getMessage());
        } catch (NullPointerException e) {
            System.out.println(" Get null! " + e.getMessage());
        } catch (IOException e) {
            System.out.println(" IN file error! " + e.getMessage());
        }
    }
}
