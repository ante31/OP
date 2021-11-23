#include<iostream>
#include <string>
#include <vector>
#include "hangman.h"

using namespace std;

int main() {
	model m;
	controller c;
	view v;
	char charGuess;

	m.movieRandomizer(m.movie);
	m.movieCensorer(m.movie, m.censoredMovie);
	//DISPLAY
	v.refreshScreen(m);

	while (c.checkGameOver(m.lives, m.censoredMovie)) {
		//USER INPUT
		charGuess = c.userEntry();
		if (c.checkLetter(charGuess, m.movie)) {
			c.updateMovieDisplay(m.movie, m.censoredMovie, charGuess);
		}
		else {
			m.usedLetters.push_back(charGuess);
			c.updateLives(m.lives);
		}
		v.refreshScreen(m);
	}
	cout << "GAME OVER" << endl;
}
