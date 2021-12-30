#include "japaneza.h"


int main() {
	int guess;
	game g;
	humanPlayer h;
	computerPlayer c;

	while (g.gameLoop(h.points, c.points)) {
		g.displayScore(h.points, c.points);
		h.inputHuman();
		c.inputComputer();

		while (true) {
			guess = h.guessHuman();
			if (g.checkGuess(c.sumOfHands, guess)) {
				g.increasePoints(h.points);
				break;
			}
			guess = c.guessComputer();
			if (g.checkGuess(h.sumOfHands, guess)) {
				g.increasePoints(c.points);
				break;
			}
		}
	}
}
