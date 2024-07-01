from cs50 import get_int

#Initate board and execute
def main():
    board = [['1', '2', '3'], ['4', '5', '6'], ['7', '8', '9']]
    updateschema(board)
    player = 1
    while True:
        decidemove(player, board)
        updateschema(board)
        if checkWin(board):
            print(f"Player {player} Wins!")
            break
        if checkTie(board):
            print("Tie!")
            break
        if player == 1:
            player = 2
        else:
            player = 1

#Input player move
def decidemove(player, board):
    while True:
        move = str(input(f"Player {player} move: "))
        for row in board:
            for i, cell in enumerate(row):
                if move == cell:
                    if player == 1:
                        row[i] = 'X'
                    else:
                        row[i] = 'O'
                    return
        print("Invalid move")

#Print the board
def updateschema(board):
    for row in board:
        print(row)

#Check if 3 in a row: horizontally, vertically, diagonally
def checkWin(board):
    for row in board:
        if row[0] == row[1] == row[2]:
            return True

        for col in range(3):
            if board[0][col] == board[1][col] == board[2][col]:
                return True

        if board[0][0] == board[1][1] == board[2][2] or board[0][2] == board[1][1] == board[2][0]:
            return True

    return False

#Check if there is a tie
def checkTie(board):
    for row in board:
        for cell in row:
            if cell.isdigit():
                return False
    return True

main()






