#include "japaneza.h"

bool game::gameLoop(int playerPoints, int computerPoints) {
	if (playerPoints >= 10 || computerPoints >= 10) {
		return 0;
	}
	return 1;
}

void humanPlayer::inputHuman() {
	int input = 1;
	int iteration = 0;
	sumOfHands = 0;
	cout << "Choose 3 or less coins among 1, 2, and 5 for the first hand: (0 for stop): " << endl;
	while (input != 0 && iteration<3) {
		cin >> input;
		if (input == 1 || input == 2 || input == 5) {
			sumOfHands += input;
			iteration++;
		}
		else {
			cout << "Invalid input! Try again" << endl;
		}
	}
	input = 1, iteration = 0;
	cout << "Choose 3 or less coins among 1, 2, and 5 for the second hand: (0 for stop): " << endl;
	while (input != 0 && iteration < 3) {
		cin >> input;
		sumOfHands += input;
		iteration++;
	}
	//cout << "PLayer: " << sumOfHands << endl;
}

void computerPlayer::inputComputer() {
	srand(time(NULL));
	int random;
	do {
		random = rand() % 31;
	} while (random == 28 || random == 29);
	sumOfHands = random;
	//cout << "Computer: " << sumOfHands << endl;
}

int computerPlayer::guessComputer() {
	srand(time(NULL));
	vector <int> v;
	int guess;
	do {
		guess = rand() % 31;
	} while (guess == 28 || guess == 29 || checkPreviousGuess(guess, v));
	cout << "Computer guess :" << guess << endl;;
	return guess;
}

bool computerPlayer::checkPreviousGuess(int guess, vector <int>& v) {
	int size = v.size();
	for (int i = 0; i < size; i++) {
		if (guess == v[i]) {
			return 0;
		}
	}
	v.push_back(guess);
	return 1;
}

int humanPlayer::guessHuman() {
	int guess;
	cout << "Human guess: ";
	do {
		cin >> guess;
	} while (guess < 0 || guess == 28 || guess == 29 || guess > 30);
	return guess;
}

bool game::checkGuess(int sum, int guess) {
	return sum == guess;
}

void game::increasePoints(int& points) {
	points++;
}

void game::displayScore(int playerPoints, int computerPoints) {
	cout << endl << "Player: " << playerPoints << "   " << "Computer: " << computerPoints << endl << endl;
}
