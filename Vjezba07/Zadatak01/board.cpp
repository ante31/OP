#include "board.h"

void Board::draw_char(int x, int y, char ch) {
	matrix[x][y] = ch;
}

void Board::draw_up_line(Point p) {

}

void Board::draw_line(Point p1, Point p2, char ch) {
	int numOfCharsInBetween = max(abs(p1.x - p2.x), abs(p1.y - p2.y));
	cout << numOfCharsInBetween << endl;
	double hypotenuse = sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
	double nthPartOfHypotenuse = hypotenuse / numOfCharsInBetween;
	cout << hypotenuse;
	cout << nthPartOfHypotenuse << endl;
	double i = 0;
	cout << "p1: (" << p1.x << ", " << p1.y << ")" << endl;
	cout << "p2: (" << p2.x << ", " << p2.y << ")" << endl;
	//Ako je x veci od y
	if (abs(p1.x - p2.x) > abs(p1.y - p2.y)) {
		if (p1.x <= p2.x && p1.y <= p2.y) {
			for (int iterationStart = p1.x; iterationStart <= p1.x + numOfCharsInBetween; iterationStart++) {
				draw_char(iterationStart, round(p1.y + i), ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
		else if (p1.x <= p2.x && p1.y >= p2.y) {
			for (int iterationStart = p1.x; iterationStart <= p1.x + numOfCharsInBetween; iterationStart++) {
				draw_char(iterationStart, round(p1.y - i), ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
		else if (p1.x >= p2.x && p1.y <= p2.y) {
			cout << "kk"<<endl;
			for (int iterationStart = p1.x; iterationStart >= p1.x - numOfCharsInBetween; iterationStart--) {
				draw_char(iterationStart, round(p1.y + i), ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
		else {
			for (int iterationStart = p2.x; iterationStart <= p2.x + numOfCharsInBetween; iterationStart++) {
				draw_char(iterationStart, round(p1.y + i), ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
	}
	else {
		if (p1.x <= p2.x && p1.y <= p2.y) {
			for (int iterationStart = p1.y; iterationStart <= p1.y + numOfCharsInBetween; iterationStart++) {
				draw_char(round(p1.x + i), iterationStart, ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
		else if (p1.x <= p2.x && p1.y >= p2.y) {
			for (int iterationStart = p1.y; iterationStart >= p2.y - numOfCharsInBetween; iterationStart--) {
				draw_char(round(p1.x + i), iterationStart, ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
		else if (p1.x >= p2.x && p1.y <= p2.y) {
			for (int iterationStart = p1.y; iterationStart <= p1.y + numOfCharsInBetween; iterationStart++) {
				draw_char(round(p1.x - i), iterationStart, ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
		else {
			for (int iterationStart = p2.y; iterationStart <= p2.y + numOfCharsInBetween; iterationStart++) {
				draw_char(round(p1.x + i), iterationStart, ch);
				i += sqrt(pow(nthPartOfHypotenuse, 2) - 1);
			}
		}
		
	}
	
}

void Board::display() {
	for (int j = 0; j < dimY; j++) {
		for (int i = 0; i < dimX; i++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Board::setToNothing(char** matrix) {
	for (int i = 0; i < dimX; i++) {
		for (int j = 0; j < dimY; j++) {
			matrix[i][j] = ' ';
		}	
	}
}
