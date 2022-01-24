/*. 
Napisati funkciju count_letter koja prima jedan po jedan znak sa ulaza. Funkcija broji broj samoglasnika
i suglasnika i baca iznimku u slučaju da je unesen znak koji nije slovo.
*/

#include <iostream>
#include <string>
using namespace std;


void funk(char c) {
	static int counter1 = 0;
	static int counter2 = 0;

	c = tolower(c);
	try {
		if (c=='a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			counter1++;
			cout << "broj samoglasnika: " << counter1 << endl;
		}
		else if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && isalpha(c)) {
			counter2++;
			cout << "broj suglasnika: " << counter2 << endl;
		}
		else
			throw exception();
	}
	catch (const exception &e) {
		cout << "iznimka"<<endl;
	}
}


int main() {
	string str = "Ovo je string";
	int size = str.size();
	for (int i = 0; i < size; i++) {
		funk(str[i]);
	}
}
