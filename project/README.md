# Tictactoe in object oriented programming
#### Video Demo:  <URL HERE>
#### Description:
Name: Victor
Github: https://github.com/Victor-268
edX username: victorgevel
City, Country: Den Bosch, The Netherlands
Date: 24/04/2024

Tictactoegame written in python using object oriented programming and procedural programming.

I wanted to understand the difference between procedural and object oriented programming. Hence, I first wrote a procedural implementation of tictactoe, then I adapted it to object oriented programming.

For the procedural method, it includes functions for initiating the game board, allowing players to make moves, updating the board after each move, checking for a win condition (either horizontally, vertically, or diagonally), and determining if the game ends in a tie. The main function orchestrates the flow of the game by alternating between players until a winner is declared or a tie occurs. Overall, the code provides a straightforward implementation of a classic game in Python.

The following code is a Python implementation of a simple Tic Tac Toe game using procedural programming techniques. Let's break down its components:
main Function:

    The main function serves as the entry point of the program.
    It initializes the game board with numbers from 1 to 9, representing the positions.
    The updateschema function is called to print the initial state of the board.
    It sets the initial player to 1.
    The game loop executes indefinitely until a win or tie condition is met.
    Within each iteration of the loop:
        The decidemove function is called to prompt the current player to make a move.
        After the move is made, the updateschema function is called to print the updated board state.
        It checks for win or tie conditions using the checkWin and checkTie functions.
        If a win or tie condition is met, the corresponding message is printed, and the loop breaks.
        The player turn is switched for the next iteration.

decidemove Function:

    The decidemove function takes the current player and the game board as parameters.
    It prompts the current player to input their move.
    It iterates through each cell of the board to find the corresponding position entered by the player.
    If the entered position is valid, it updates the board with the player's mark ('X' or 'O').
    If the entered position is invalid, it prompts the player to enter a valid move.

updateschema Function:

    The updateschema function takes the game board as a parameter.
    It iterates through each row of the board and prints its contents, displaying the current state of the game board.

checkWin Function:

    The checkWin function takes the game board as a parameter.
    It checks for a win condition by examining each row, column, and diagonal of the board.
    If any row, column, or diagonal contains three identical marks ('X' or 'O'), it returns True indicating a win.
    If no win condition is found, it returns False.

checkTie Function:

    The checkTie function takes the game board as a parameter.
    It checks for a tie condition by iterating through each cell of the board.
    If any cell contains a digit (representing an empty position), it returns False indicating the game is not tied.
    If all cells are filled with marks ('X' or 'O'), it returns True indicating a tie.

The object-oriented version of Tic Tac Toe game is organized into three classes: Board, Player, and Game. The Board class initializes the game board, provides methods to print the board, check for a win condition, and determine if there's a tie. The Player class initializes a player object and prompts the player to make a move. The Game class handles the main logic of the game, including player turns, updating the board, and checking for win conditions or ties. Overall, the code offers a structured approach to implementing the Tic Tac Toe game using object-oriented programming concepts.

The following code presents a comprehensive implementation of a Tic Tac Toe game using object-oriented programming (OOP) principles in Python. Let's delve into each component in detail:
Board Class:

    The Board class encapsulates the game board and its functionalities.
    In the constructor method __init__, a 2D list self.board is initialized to represent the game board with numbers from 1 to 9, which correspond to the positions.
    The updateschema method prints the current state of the board, displaying the positions and player moves.
    The checkwin method is responsible for determining if there's a win condition on the board. It examines each row, column, and diagonal to check if any player has achieved three consecutive marks (either 'X' or 'O').
    The checkTie method checks if the game has reached a tie condition by inspecting if all positions on the board are filled with 'X' or 'O', indicating that no further moves are possible.

Player Class:

    The Player class represents individual players participating in the game.
    The constructor method __init__ initializes a player object with a player number (1 or 2), indicating their turn in the game.
    The decidemove method facilitates player interaction by prompting them to make a move. It takes the current state of the board as input and updates it based on the player's choice of position.

Game Class:

    The Game class serves as the orchestrator of the Tic Tac Toe game.
    In the constructor method __init__, an instance of the Board class is created, providing access to the game board and its functionalities.
    The main method governs the main logic of the game. It initiates the game by displaying the initial state of the board using the updateschema method. Then, it enters a loop where players take turns making moves until a win or tie condition is met.
        Within the loop, players are prompted to make moves using instances of the Player class.
        After each move, the board state is updated and displayed.
        The loop terminates if a player wins (determined by checkwin method) or if the game ends in a tie (determined by checkTie method).
        The outcome of the game (win or tie) is printed to the console.


