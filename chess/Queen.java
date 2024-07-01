public class Queen extends Piece {
    public Queen(Color color, Position position){
        super(color, position);
    }

    @Override
    public boolean validMove(Position newPosition, Board[][] board){
        if (newPosition.equals(this.position)) {
            return false;
        }

        int rowDiff = Math.abs(this.position.getRow() - newPosition.getRow());
        int colDiff = Math.abs(this.position.getColumn() - newPosition.getColumn());

        boolean straight = this.position.getRow() == newPosition.getRow() || this.position.getColumn() == newPosition.getColumn();
        boolean diagonal = rowDiff == colDiff;

        if (!straight && !diagonal){
            return false;
        }

        int rowDir = Integer.compare(newPosition.getRow(), this.position.getRow());
        int colDir = Integer.compare(newPosition.getColumn(), this.position.getColumn());
        int steps;

        if(straight){
            steps = Math.max(rowDiff, colDiff);
        }
        else{
            steps = rowDiff - 1;
        }

        //check if piece in the way
        for (int i = 1; i <= steps; i++) {
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
