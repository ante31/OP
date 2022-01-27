/*.
(15) Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova, svaki string preokrene
te sortira vektor po preokrenutim stringovima.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fun(string str) {
	static vector <string> strings;
	reverse(str.begin(), str.end());
	strings.push_back(str);
	sort(strings.begin(), strings.end());

	//print
	int size = strings.size();
	for (int i = 0; i < size; i++) {
		cout << strings[i] << endl;
	}
	cout << endl;
}

int main() {
	string str;

	cin >> str;
	fun(str);
	cin >> str;
	fun(str);
	cin >> str;
	fun(str);
}
