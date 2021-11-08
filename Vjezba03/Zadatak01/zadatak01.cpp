#include "zadatak01.h"

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void zadatak01::vector_number(vector <int> &v1, int n)
{
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v1.push_back(num);
	}
}

void zadatak01::vector_interval(vector <int>& v1, int a, int b)
{
	int num;
	cin >> num;
	while ((num >= a) && (num <= b))
	{
		v1.push_back(num);
		cin >> num;
	}
}

void zadatak01::vector_printout(vector <int> v1)
{
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << "\n";
}
