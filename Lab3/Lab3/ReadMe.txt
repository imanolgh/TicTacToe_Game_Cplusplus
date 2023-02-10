Imanol Herrero - i.herrero@wustl.edu, 457666
CSE 332
Lab 3

Program Summary: 
In this lab I build a game of tic tac toe. I built a 5x5 tic tac toe board in which any row or column coordinate which is less than 1
or greater than 4 is an invalid coordinate.  In other words, the board lies within valid coordinates ranging from 1 to 3 (inclusive)
for rows and columns.  The game has two players, Player X and Player O, who enter coordinates corresponding to where they 
want to play their pieces. When the game begins, Player X is the first player to make a move. After each player makes
a valid move, the current player alternates and the turn increases by 1. 
If all positions on the board are full but neither player got 3 in 
a row (vertically, horizontally, or diagonally), the game ends in a draw and a message is printed out.

How To Run:
Enter 'Lab3.exe TicTacToe' to run the game.  

File Summary:
There are 2 files in my program.  Game.h is the header file which declares the constructor of the Game class with its
associated member variables and member functions, command line arguments and their associated error enums, as well as game state enums.  It also declares the
ostream operator that takes a reference to an ostream o, and a reference to a game class object as
parameters, and returns the ostream reference that was passed.  This insertion operator is declared as a friend
in order to access the private member variables of the game object.

Lab3.cpp contains the main function, constructor definitition, and member function definitions of the Game class.
In the main function, a 'letsPlay' object of the Game class is declared and calls the object's play() method.

Error Messages Program Can Generate:  
Success - occurs when program executes with no errors 
programName - occurs when an incorrect program name is used to run the program
fileInput - occurs when an incorrect argument is passed to the program to run it.
incorrect_cmd_ln_args - occurs when an incorrect number of command line arguments are passeed to run the program
incorrectArg - occrs when incorrect arguments are passed to run the program.
incorrectName - occurs when the input is not 'TicTacToe'

Tests cases: 
- command line argument other than 'TicTacToe' 
- Incorrect number of command line arguments
- Invalid syntax for coordinates (i.e. 1,    1 or 1 1 or 123 or 11,1 etc)
- Coordinates that are out of bounds (i.e. 0,1 or 1,0 or 4,1 or 1,4 or 4,4 or 0,0 etc)
- If the players draw
- If a player quits

Common Errors:
An error I was stuck on for a long time was this one:
'error C2109: subscript requires array or pointer type'
It was because I was defining my member variables of the constructor using '=' instead of inside parentheses.
