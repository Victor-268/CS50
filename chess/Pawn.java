public class Pawn extends Piece{
    public Pawn(Color color, Position position){
        super(color, position);
    }

    @Override
    public boolean validMove(Position newPosition, Board[][] board){
        if (newPosition.equals(this.position)) {
            return false;
        }

        int forwardDirection;
        if (color == Color.WHITE) {
            forwardDirection = -1;
        }
        else {
            forwardDirection = 1;
        }

        int rowDiff = (newPosition.getRow() - position.getRow())* forwardDirection;
        int colDiff = newPosition.getColumn() - position.getColumn();

        //Check if forward move is possible
        if (colDiff == 0 && rowDiff == 1 && board[newPosition.getRow()][newPosition.getColumn()] == null){
            return true;
        }

        //Check if in initial state for double move
        boolean isStartingPos = (color == Color.WHITE && position.getRow() == 6) || (color == Color.BLACK && position.getRow() == 1);
        if (colDiff == 0 && rowDiff == 2 && isStartingPos && board[newPosition.getRow()][newPosition.getColumn()] == null && board[position.getRow() + forwardDirection][position.getColumn()] == null) {
            return true;
        }

        //Check if diagonal attack is possible
        if (Math.abs(colDiff) == 1 && rowDiff == 1 && board[newPosition.getRow()][newPosition.getColumn()] != null && board[newPosition.getRow()][newPosition.getColumn()].color != this.color){
            return true;
        }

        return false;

    }
}
