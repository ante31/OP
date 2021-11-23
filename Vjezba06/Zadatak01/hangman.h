#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <vector>

using namespace std;

class model {
	public:
		string movie;
		string censoredMovie;
		string guessMovie;
		vector <char> usedLetters;
		int lives = 7;
		bool inGame = true;
		void movieRandomizer(string& movie);
		void movieCensorer(string movie, string& censoredMovie);
};

class controller {
	public:
		char userEntry();
		bool checkLetter(char charGuess, string movie);
		void updateLives(int &lives);
		void updateMovieDisplay(string movie, string& censoredMovie, char charGuess);
		bool checkGameOver(int lives, string censoredMovie);

};

class view {
	public:
		void refreshScreen(model m);
		void displayCurrentProgress(string movie, string censoredMovie, int lives);
		void displayUsedLetters(vector <char> &usedLetters);
		void displayHangman(int lives);
};
#endif 

