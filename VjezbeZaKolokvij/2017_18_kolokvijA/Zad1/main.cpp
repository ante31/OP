/*.
U datoteci su dane koordinate točaka (x, y, z) tako da je u svakom redu jedna točka. Napisati program
koji transformira sve z-koordinate primjenjujući funkciju fun(x, y, z) gdje je fun funkcija

fun(x, y, z) = z + x2 + y2

te nove koordinate zapisuje u drugu datoteku. Operacije transformiranja i čitanja i pisanja u datoteku
realizirati koristeći standardnu biblioteku.
*/

#include <iostream>
#include <fstream>

using namespace std;

int fun(int x, int y, int z) {
	return z + x * x + y * y;
}

int main() {
	int x, y, z;
	ifstream file;
	ofstream novi;
	file.open("brojevi.txt");
	novi.open("brojevi2.txt");
	if (!file.is_open()) {
		cout << "greska";
	}
	while (file >> x && file >> y && file >> z) {
		z = fun(x, y, z);
		novi << z << " ";
	}
}
