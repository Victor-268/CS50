public class Bishop extends Piece{
    public Bishop(Color color, Position position){
        super(color, position);
    }

    @Override
    public boolean validMove(Position newPosition, Board[][] board){
        if (newPosition.equals(this.position)) {
            return false;
        }

        int rowDiff = Math.abs(this.position.getRow() - newPosition.getRow());
        int colDiff = Math.abs(this.position.getColumn() - newPosition.getColumn());

        //check if diagonal
        if (rowDiff != colDiff){
            return false;
        }

        int rowDir, colDir;
        if (newPosition.getRow() > position.getRow()) {
            rowDir = 1;
        } else {
            rowDir= -1;
        }

        if (newPosition.getColumn() > position.getColumn()) {
            colDir = 1;
        } else {
            colDir = -1;
        }
        int steps = rowDiff - 1;

        //check if piece in the way
        for (int i = 1; i < steps; i++) {
            if (board[position.getRow() + i * rowDir][position.getColumn() + i * colDir] != null) {
                return false;
            }
        }

        //check destination square row
        Piece destPiece = board[newPosition.getRow()][newPosition.getColumn()];
        if (destPiece == null){
            return true;
        }
        else if (!destPiece.getColor().equals(this.getColor())) {
            return true;
        }
        return false;
    }


}
