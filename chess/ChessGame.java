public class ChessGame {
    private ChessBoard board;
    private boolean whiteTurn = true;

    //initate the game & board
    public ChessGame() {
        this.board = new ChessBoard();
    }

    //make move
    public boolean makeMove(Position start, Position end){
        Piece movingPiece = board.getPiece(start.getRow(), start.getColumn());
        if (movingPiece == null || movingPiece.getColor() != (whiteTurn ? Color.WHITE : Color.BLACK)){
            return false;
        }

        if (movingPiece.validMove(end, board)){
            board.movePiece(start, end);
            whiteTurn = !whiteTurn;
            return true;
        }
        return false;
    }

    //find the kings position
    public Position findKing(Color color) {
        for (int row = 0; row < board.getBoard().length; row++) {
            for (int col = 0; col < board.getBoard()[row].length; col++) {
                Piece piece = board.getPiece(row, col);
                if (piece instanceof King && piece.getColor() == color) {
                    return new Position(row, col);
                }
            }
        }
        throw new RuntimeException("King not found");
    }

    //check if check
    public boolean check(Color kingColor){
        Position kingPosition = findKing(kingColor);
        for (int row = 0; row < board.getBoard().length; row++ ){
            for (int col = 0; col < board.getBoard()[row].length; col++ ){
                Piece piece = board.getPiece[row][col];
                if (piece != null && piece.getColor() != kingColor){
                    if (piece.validMove(kingPosition, board.getBoard())){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    //check if checkmate
    public boolean checkMate(Color kingColor){
        if (!check(kingColor)) {
            return false;
        }

        Position kingPosition = findKing(kingColor);
        King king = (King) board.getPiece(kingPosition.getRow(), kingPosition.getColumn());

        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }
                Position newPosition = new Position(kingPosition.getRow() + row, kingPosition.getColumn() + col);
                if (positionOnBoard(newPosition) && king.isValidMove(newPosition, board) && !nextCheck(kingColor, kingPosition, newPosition)) {
                    return false; // If there's any valid move that gets the king out of check, it's not checkmate
                }
            }
        }
        return true; // If no valid moves get the king out of check, it's checkmate
    }

    //check if position is on board
    private boolean positionOnBoard(Position position){
        return position.getRow() >= 0 && position.getRow() < 8 && position.getColumn() >=0 && position.getColumn() < 8;
    }

    //check if next position in in check
    private boolean nextCheck(Color kingColor, Position position, Position newPosition){
        Piece temp = board.getPiece(newPosition.getRow(), newPosition.getColumn());
        board.setPiece(newPosition.getRow(), newPosition.getColumn(), board.getPiece(position.getRow(), position.getColumn()));
        board.setPiece(position.getRow(), position.getColumn(), null);
        boolean inCheck = check(kingColor);
        board.setPiece(position.getRow(), position.getColumn(), board.getPiece(newPosition.getRow(), newPosition.getColumn()));
        board.setPiece(newPosition.getRow(), newPosition.getColumn(), temp);
        return inCheck;
    }
}
