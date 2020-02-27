package HW10;

/**
 * @author Georgiy Korneev (kgeorgiy@kgeorgiy.info)
 */
public interface Position {
    boolean isValid(Move move);

    Cell getCell(int r, int c);

    int getRows();

    int getColumns();

    int getK();
}