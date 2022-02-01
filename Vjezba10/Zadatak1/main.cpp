/*
Napisati template funkciju za sortiranje niza. Napisati specijalizaciju
te funkcije za niz char-ova u kojoj nece biti razlike izmedu malih i velikih slova
*/

#include <iostream>

using namespace std;

template<typename TYPE>
void sort(TYPE array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i] < array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}

template<>
void sort<char>(char array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tolower(array[i]) < tolower(array[j])) {
                swap(array[i], array[j]);
            }
        }
    }
}

int main()
{
    int numbers[] = {1, 10, 4, 78, 32, 94, 23 };
    char letters[] = { 'l', 't', 'g', 'A', 'H', 'w'};
    sort(numbers, 7);
    sort(letters, 6);
    for (int i = 0; i < 7; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 6; i++) {
        cout << letters[i] << " ";
    }
}


