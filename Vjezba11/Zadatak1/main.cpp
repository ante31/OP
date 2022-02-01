#include <fstream>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

using namespace std;

void readToVector(const string& fileName, vector<int>& intVector)
{
	ifstream file;
	int tmp;

	file.open(fileName);
	if (file.fail()) {
		throw exception();
	}

	istream_iterator<int> it(file);
	istream_iterator<int> eos;
	copy(it, eos, back_inserter(intVector));

}

int main()
{
	vector<int> intVector;
	string fileName = "numbers.txt";

	try {
		readToVector(fileName, intVector);
	}
	catch (const exception& e) {
		cerr << "Unable to open file " << fileName << endl;
		exit(1);
	}

	int size = intVector.size();
	for (int i = 0; i < size; i++) {
		cout << intVector[i] << " ";
	}
	cout << endl << endl;

	int greaterThan500 = count_if(intVector.begin(), intVector.end(), [](int i) { return i > 500; });
	cout << "Numbers greater than 500: " << greaterThan500 << endl << endl;

	int minElement = *min_element(intVector.begin(), intVector.end());
	int maxElement = *max_element(intVector.begin(), intVector.end());

	cout << "Min element is: " << minElement << endl << "Max element is: " << maxElement << endl;

	vector<int>::iterator it;

	it = remove_if(intVector.begin(), intVector.end(), [](int i) { return i < 300; });
	intVector.resize(std::distance(intVector.begin(), it));
	sort(intVector.begin(), intVector.end(), greater<int>());

	size = intVector.size();
	for (int i = 0; i < size; i++) {
		cout << intVector[i] << " ";
	}
}
