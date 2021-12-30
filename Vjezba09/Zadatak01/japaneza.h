#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;




class game {
public:
	void displayScore(int playerPoints, int computerPoints);
	bool gameLoop(int playerPoints, int computerPoints);
	bool checkGuess(int sum, int guess);
	void increasePoints(int& points);
};

class player {
public:
	int points = 0;
	int sumOfHands = 0;
};

class humanPlayer : public player{
public:
	void inputHuman();
	int guessHuman();
};

class computerPlayer : public player {
public:	
	void inputComputer();
	int guessComputer();
	bool checkPreviousGuess(int guess, vector <int>& v);
};
