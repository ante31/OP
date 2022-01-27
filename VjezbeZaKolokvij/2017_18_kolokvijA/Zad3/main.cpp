/*.
Napisati template klasu za skup. U klasi treba biti omogućeno dodavanje elemenata u skup, brisanje svih
elemenata skupa, presjek i unija s drugim skupom.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Array {
public:
    vector <T> skup;
    int size;

    void add(int broj) {
        skup.push_back(broj);
    }
    void print() {
        int size = skup.size();
        for (int i = 0; i < size; i++) {
            cout << skup[i] << endl;
        }
    }
    void skup_union(Array<typename T>& skup1, Array<typename T>& skup2) {
        int size1 = skup1.skup.size();
        int size2 = skup2.skup.size();
        vector <T> unija;

        for (int i = 0; i < size1; i++) { //345
           
            if (find(unija.begin(), unija.end(), skup1.skup[i]) == unija.end()) {
                unija.push_back(skup1.skup[i]);
            }
        }
        for (int i = 0; i < size2; i++) {//567
            if (find(unija.begin(), unija.end(), skup2.skup[i]) == unija.end()) {
                unija.push_back(skup2.skup[i]);
            }
           
        }
        //print
        int unionSize = unija.size();
        cout << "Unija :" << endl;
        for (int i = 0; i < unionSize; i++) {
            cout << unija[i] << endl;
        }
    }

   void skup_intersection(Array<typename T> skup1, Array<typename T> skup2) {
        int size1 = skup1.skup.size();
        int size2 = skup2.skup.size();
        vector <T> presjek;

        for (int i = 0; i < size1; i++) { //345

            if (find(skup2.skup.begin(), skup2.skup.end(), skup1.skup[i]) != skup2.skup.end()) {
                presjek.push_back(skup1.skup[i]);
            }
        }
        
        int intersectionSize = presjek.size();
        cout << "Presjek :" << endl;
        for (int i = 0; i < intersectionSize; i++) {
            cout << presjek[i] << endl;
        }

    }

    
};

int main() {
    Array<int> arr1;
    arr1.add(3);
    arr1.add(4);
    arr1.add(5);

    Array<int> arr2;
    arr2.add(5);
    arr2.add(6);
    arr2.add(7);
   
    arr1.print();
    arr2.print();

    arr1.skup_union(arr1, arr2);
    arr1.skup_intersection(arr1, arr2);
    
}
