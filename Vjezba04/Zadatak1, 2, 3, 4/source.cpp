#include "PointWeaponTarget.h"
#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));
	const int n = 10;
	Target targetObj[n];
	Weapon weaponObj;

	action(weaponObj, targetObj, n);
}
