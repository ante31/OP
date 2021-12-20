#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class timer {
	int h;
	int m;
	double s;
public:
	timer() {
		h = 0;
		m = 0;
		s = 0;
	}

	timer(int x, int y, double z) {
		h = x;
		m = y;
		s = z;
	}

	timer operator += (const timer t);

	timer operator /= (int v);

	friend ostream& operator<<(ostream& output, const timer t);

	bool operator<(const timer& other);

	timer operator=(const timer& other);

	double operator - (const timer& other);

	int getH(timer t);
	int getM(timer t);
	int getS(timer t);
};

class penalty {
	int h;
	int m;
	int s;
public:
	penalty(int sec) {
		s = sec;
	}

	penalty operator()(timer t);

};
