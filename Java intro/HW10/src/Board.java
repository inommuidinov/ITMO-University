package HW10;

public interface Board {
    Position getPosition();

    Cell getCell();

    Result makeMove(Move move);

    void clean();
}