#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#define max(a, b) ((a)>(b)? (a): (b))
#define min(a, b) ((a)>(b)? (b): (a))
using namespace std;

struct Point {
	double x;
	double y;
	//Konstruktor za Point
	Point(int a, int b) {
		x = a;
		y = b;
	}
};

class Board {
public:
	char borderChar;
	int dimX;
	int dimY;
	char** matrix;

	void setToNothing(char** matrix);

	//Konstruktor
	Board() {
		dimX = 10;
		dimY = 10;
		borderChar = 'o';

		// Declare a memory block of size x
		matrix = new char* [dimX];
		for (int counter = 0; counter < dimX; counter++)
		{
			// Declare a memory block of size y
			matrix[counter] = new char[dimY];
		}
		setToNothing(matrix);

		for (int i = 0; i < dimX; i++) {
			draw_char(i, 0, borderChar);
			draw_char(i, dimY - 1, borderChar);
		}
		for (int i = 0; i < dimY; i++) {
			draw_char(0, i, borderChar);
			draw_char(dimX - 1, i, borderChar);
		}
	}

	//Konstruktor s argumentima
	Board(int x, int y) {
		borderChar = 'o';
		dimX = x;
		dimY = y;
		// Declare a memory block of size x
		matrix = new char* [dimX];
		for (int counter = 0; counter < dimX; counter++)
		{
			// Declare a memory block of size y
			matrix[counter] = new char[dimY];
		}
		setToNothing(matrix);

		for (int i = 0; i < dimX; i++) {
			draw_char(i, 0, borderChar);
			draw_char(i, dimY - 1, borderChar);
		}
		for (int i = 0; i < dimY; i++) {
			draw_char(0, i, borderChar);
			draw_char(dimX - 1, i, borderChar);
		}
	}

	//Copy konstruktor 
	//Move konstruktor 

	//Destruktor
	/*~Board() {
		delete& dimX;
		delete& dimY;
		delete matrix;
	}*/

	void draw_char(int x, int y, char borderChar);
	void draw_up_line(Point p);
	void draw_line(Point p1, Point p2, char ch);
	void display();
};
#endif
