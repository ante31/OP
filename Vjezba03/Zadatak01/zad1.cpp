//Napišite funkciju koja stringove, koje korisnik unosi, sprema u vektor stingova,
//svaki string preokrene te sortira vektor po preokrenutim stringovima

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void vector_number(vector <int> &v1, int n)
{
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v1.push_back(num);
    }
}

void vector_interval(vector <int>& v1, int a, int b)
{
    int num;
    cin >> num;
    while ((num >= a) && (num <= b))
    {
        v1.push_back(num);
        cin >> num;
    }
}

void vector_printout(vector <int> v1)
{
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << "\n";
}
int main()
{
    vector <int> v1;
    vector_number(v1, 3);
    vector_interval(v1, 1, 10);
    vector_printout(v1);
}
