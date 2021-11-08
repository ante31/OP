#include "zadatak01.h"

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	zadatak01 vec;
	vector <int> v1;
	vec.vector_number(v1, 3);
	vec.vector_interval(v1, 1, 10);
	vec.vector_printout(v1);
}
