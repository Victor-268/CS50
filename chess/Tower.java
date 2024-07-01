public class Tower extends Piece{
    public Tower(Color color, Position position){
        super(color, position);
    }

    @Override
    public boolean validMove(Position newPosition, Board[][] board){
        if (newPosition.equals(this.position)) {
            return false;
        }

        //check if there is a piece in the way horizontally
        if (position.getRow() == newPosition.getRow()) {
            int columnStart = Math.min(position.getColumn(), newPosition.getColumn());
            int columnEnd = Math.max(position.getColumn(), newPosition.getColumn());
            for (int column = columnStart; column < columnEnd; column++){
               if (board[position.getRow()][column] != null){
                  return false;
              }
            }
        }
        //check if there is a piece in the way vertically
        else if (position.getColumn() == newPosition.getColumn()){
            int rowStart = Math.min(position.getRow(), newPosition.getRow());
            int rowEnd = Math.max(position.getRow(), newPosition.getRow());
            for (int row = rowStart; row < rowEnd; row++){
               if (board[position.getColumn()][row] != null){
                  return false;
              }
            }
        }
        //unvalid move
        else {
            return false;
        }
        //check destination square row
        Piece destPiece = board[newPosition.getRow()][newPosition.getColumn()];
        if (destPiece == null){
            return true;
        }
        else if (destPiece.getColor() != this.getColor()) {
            return true;
        }
        return false;
    }
}
