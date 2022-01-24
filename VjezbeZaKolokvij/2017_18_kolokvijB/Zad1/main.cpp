/*. 
Napisati klasu razlomak. Napisati funkciju koja puni vektor razlomaka iz datoteke, te sve elemente vektora
skrati. Za punjenje vektora i skraćivanje koristiti funkcije standardne biblioteke.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class razlomak {
public:
	int a;
	int b;
	// a/b

	razlomak(int num1, int num2) {
		a = num1;
		b = num2;
	}
};

vector <razlomak> citac() {
	ifstream f;
	vector <razlomak> razlomci;
	int num1, num2;


	f.open("brojevi.txt");
	if (!f) {
		cout << "nema" << endl;
		return razlomci;
	}
	while (f >> num1 && f >> num2) {
		razlomak r(num1, num2);
		
		razlomci.push_back(r);
	}
	return razlomci;
}

int nzd(int a, int b) {
	//najveci zajednicki djeljitelj
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void skrati(vector <razlomak>& razlomci) {
	int size = razlomci.size();
	int d;

	for (int i = 0; i < size; i++) {
		d = nzd(razlomci[i].a, razlomci[i].b);

		razlomci[i].a /= d;
		razlomci[i].b /= d;
	}
}

void print(vector <razlomak> razlomci) {
	int size = razlomci.size();
	for (int i = 0; i < size; i++) {
		cout << razlomci[i].a << "/" << razlomci[i].b << endl;
	}
}


int main() {
	vector <razlomak> razlomci = citac();

	skrati(razlomci);
	print(razlomci);
}
