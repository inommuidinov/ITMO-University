import java.io.*;
import java.util.*;
import java.sql.SQLOutput;
import java.nio.charset.StandardCharsets;

interface Checker {
    boolean isWordCharacter(char c);
}

public class FastScanner implements  AutoCloseable {
    private InputStreamReader reader;
    private char saved;
    private boolean hasSaved;
    private Checker checker;

    public FastScanner(String inputFile, Checker check) throws IOException {
            checker = check;
            reader = new InputStreamReader(new FileInputStream(inputFile), StandardCharsets.UTF_8);
            hasSaved = false;
            saved = 0;
    }
    public void close() {
        try {
            reader.close();
        } catch (IOException e) {
            System.out.println("Can't close the reader !");
        }
    }
    private boolean readInput() throws IOException {
        if (!hasSaved) {
            int res = reader.read();
            if (res < 0) {
                return  false;
            }
            saved = (char) res;
            hasSaved = true;
        }
        return  true;
    }
    private boolean hasInput() throws IOException {
        return (hasSaved) || readInput();
    }
    private void skip(Checker checker) throws IOException {
        while (hasInput() && !checker.isWordCharacter(saved) && saved != '\n') {
            hasSaved = false;
        }
    }
    public void skipLine(Checker checker) throws IOException {
        while (hasInput()) {
            if (saved == '\n') {
                hasSaved = false;
                readInput(); break;
            }
            hasSaved = false;
        }
    }
    public boolean isEndOfLine() throws IOException {
        skip(checker);
        return !hasInput() || saved == '\n';
    }
    public String next() throws IOException {
        skip(checker);
        StringBuilder res = new StringBuilder();
        while (hasInput() && checker.isWordCharacter(saved)) {
            res.append(saved);
            hasSaved = false;
        }
        return res.toString();
    }
    public ArrayList<String> getWordInLine() throws IOException {
        ArrayList<String> tmp = new ArrayList<>();
        while (!isEndOfLine() && hasNext()) {
            tmp.add(next());
        }
        return tmp;
    }
    public boolean hasNext() throws IOException {
        while (hasInput() && !checker.isWordCharacter(saved)) {
            hasSaved = false;
        }
        return hasInput();
    }
}