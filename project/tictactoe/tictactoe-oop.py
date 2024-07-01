class Board:
    def __init__ (self):
        self.board = [['1', '2', '3'], ['4', '5', '6'], ['7', '8', '9']]

    #Print the board
    def updateschema(self):
        for row in self.board:
            print(row)

    #Check if 3 in a row: horizontally, vertically, diagonally
    def checkwin(self):
        for row in self.board:
            if row[0] == row[1] == row[2]:
                return True

        for col in range(3):
            if self.board[0][col] == self.board[1][col] == self.board[2][col]:
                return True

        if self.board[0][0] == self.board[1][1] == self.board[2][2] or self.board[0][2] == self.board[1][1] == self.board[2][0]:
            return True

        return False

    #Check if there is a tie
    def checkTie(self):
        for row in self.board:
            for cell in row:
                if cell.isdigit():
                    return False
        return True

class Player:
    def __init__(self, player):
        self.player = player

    #Input player move
    def decidemove(self, board):
        while True:
            move = str(input(f"Player {self.player} move: "))
            for row in board:
                for i, cell in enumerate(row):
                  if move == cell:
                        if self.player == 1:
                            row[i] = 'X'
                        else:
                            row[i] = 'O'
                        return
            print("Invalid move")

class Game:
    def __init__(self):
        self.board = Board()

    #Main logic
    def main(self):
        self.board.updateschema()
        while True:
            Player(1).decidemove(self.board.board)
            self.board.updateschema()
            if self.board.checkwin():
                print("Player 1 Wins!")
                break
            if self.board.checkTie():
                print("Tie!")
                break
            Player(2).decidemove(self.board.board)
            self.board.updateschema()
            if self.board.checkwin():
                print("Player 2 Wins!")
                break
            if self.board.checkTie():
                print("Tie!")
                break

Game().main()
