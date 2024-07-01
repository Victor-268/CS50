public class King extends Piece{
    public King(Color color, Position position){
        super(color, position);
    }

    @Override
    public boolean validMove(Position newPosition, Board[][] board){
        if (newPosition.equals(this.position)) {
            return false;
        }
        int rowDiff = Math.abs(this.position.getRow() - newPosition.getRow());
        int colDiff = Math.abs(this.position.getColumn() - newPosition.getColumn());

        if  (!(rowDiff !=1 && colDiff != 1 || rowDiff == 1 && colDiff == 0 || rowDiff == 0 && colDiff == 1)){
            return false;
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

