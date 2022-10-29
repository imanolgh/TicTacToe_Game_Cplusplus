#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;


enum cmd_ln_arguments { programName = 0, fileInput = 1, incorrect_cmd_ln_args = 2, incorrectArg = 3, incorrectName = 4 };


enum state { succeeded = 0, failed = 1, playerQuit = 2, notDraw = 2, user_input_invalid = 3, isDraw = 4 };

class Game {
	friend ostream& operator<< (ostream& o, const Game& TicTacToe);
private:
	char gameBoard[5][5];
	int turns;
	char playerX;
	char playerO;
	bool quitted;
	char space;
	bool moveIsValid;
	bool victoryX;
	bool victoryO;

public:
	Game();
	bool done();
	bool draw();
	int turn();
	int play();
	int prompt(unsigned int&, unsigned int&);

};

ostream& operator<< (ostream& o, const Game& TicTacToe);

int usageMessage(char* programName);