public class ChessBoard {
    private Board[][] board;

    //initiate board
    public ChessBoard(){
        this.board = new Board[8][8];
        setupPieces();
    }

    public Piece[][] getBoard(){
        return board;
    }

    public Piece getPiece(int row, int column){
        return board[row][column];
    }

    public void setPiece(int row, int column, Piece piece){
        board[row][column] = piece;
        if (piece != null){
            piece.setPosition(new Position(row, column));
        }
    }

    //setup pieces at start
    private void setupPieces(){
        for (int i = 0; i < 8; i++){
            board[1][i] = new Pawn(Color.Black, new Position[1][i]);
            board[6][i] = new Pawn(Color.White, new Position[6][i]);
        }
        board[0][0] = new Tower(Color.Black, new Position[0][0]);
        board[0][7] = new Tower(Color.Black, new Position[0][7]);
        board[7][7] = new Tower(Color.White, new Position[7][7]);
        board[7][0] = new Tower(Color.White, new Position[7][0]);

        board[0][1] = new Horse(Color.Black, new Position[0][1]);
        board[0][6] = new Horse(Color.Black, new Position[0][6]);
        board[7][6] = new Horse(Color.White, new Position[7][6]);
        board[7][1] = new Horse(Color.White, new Position[7][1]);

        board[0][2] = new Bishop(Color.Black, new Position[0][2]);
        board[0][5] = new Bishop(Color.Black, new Position[0][5]);
        board[7][5] = new Bishop(Color.White, new Position[7][5]);
        board[7][2] = new Bishop(Color.White, new Position[7][2]);

        board[0][3] = new Queen(Color.Black, new Position[0][3]);
        board[7][3] = new Queen(Color.White, new Position[7][3]);
        board[0][4] = new King(Color.Black, new Position[0][4]);
        board[7][4] = new King(Color.White, new Position[7][4]);
    }

    public void movePiece(Position start, Position end){
        if (board[start.getRow()][start.getColumn()] != null && board[start.getRow()][start.getColumn()].validMove(end, board)){
            //perform move
            board[end.getRow()][end.getColumn()] = board[start.getRow()][start.getColumn()];
            //update board
            board[end.getRow()][end.getColumn()].setPosition(end);
            //clear start position
            board[start.getRow()][start.getColumn()] = null;
        }
    }
}
