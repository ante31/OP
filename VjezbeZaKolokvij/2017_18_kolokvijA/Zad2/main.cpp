/*.
Napisati funkciju koja prima vektor brojeva, te računa korijen i logaritam broja. Funkcija baca iznimku ako
matematička operacija nije validna (korijen se može izračunati samo za nenegativne brojeve, a logaritam
samo za strogo pozitivne brojeve).
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void funkcija(vector <int> arr) {
	int size = arr.size();
	float n;
	for (int i = 0; i < size; i++) {
		try {
			if (arr[i] >= 0) {
				n = sqrt(arr[i]);
				cout << "Korijen od " << arr[i] << " je " << n << endl;
			}
			else
				throw(404);
			if (arr[i] > 0) {
				n = log10(arr[i]);
				cout <<"Logaritam od "<< arr[i]<<" je "<< n << endl;
			}
			else
				throw(505);
			
		}

		catch (int error) {
			cout << "Broj nije prikladan za matematicku uperaciju" << endl;
		}
	}
}

int main() {
	vector <int> arr = {1, 4, 63, -31, 0, 7, 23};
	funkcija(arr);
}
