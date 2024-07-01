public abstract class Piece {
    protected Position position;
    protected Color color;

    public Piece(Position position, Color color){
        this.color = color;
        this.position = position;
    }

    public Color getColor(){
        return color;
    }

    public Position getPosition(){
        return position;
    }

    public Position setPosition(){
        this.position = position;
    }

    public abstract boolean validMove(Position position, Board[][] board)
}
