#include "PointWeaponTarget.h"

#include <iostream>
#include <vector>

using namespace std;

Point Point::setToZero(Point p) {
	p.x = 0;
	p.y = 0;
	p.z = 0;
	return p;
};
Point Point::setToRandom(Point p, double a, double b) {
	p.x = (b - a) * ((((double)rand()) / (double)RAND_MAX)) + a;
	p.y = (b - a) * ((((double)rand()) / (double)RAND_MAX)) + a;
	p.z = (b - a) * ((((double)rand()) / (double)RAND_MAX)) + a;
	return p;
};
double* Point::getValue(Point p) {
	double pValues[] = { p.x, p.y, p.z };
	return pValues;
};
double Point::distance2D(Point p1, Point p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}
double Point::distance3D(Point p1, Point p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	double dz = p1.z - p2.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}
void Weapon::shoot(Weapon w)
{
	if (w.ammoCurrent)
		w.ammoCurrent--;
	else(reload(w));
}

void Weapon::reload(Weapon w) {
	w.ammoCurrent = w.ammoCapacity;
}

void action(Weapon w, Target* t, int n) {
	int numOfHits = 0, numOfHitsOneReload;
	cout << "Weapon z: " << w.weaponPoint.z << endl;
	for (int i = 0; i < n; i++) {
		cout << "TargetLowerZ " << i << " z: " << t[i].lowerLeft.z << endl;
		cout << "TargetUpperZ " << i << " z: " << t[i].upperRight.z << endl;
		if (w.weaponPoint.z <= t[i].upperRight.z && w.weaponPoint.z >= t[i].lowerLeft.z) {
			w.shoot(w);
			t[i].hitStatus = true;
			numOfHits++;
			cout << "Hit "<<i << endl;
		}
		if (w.ammoCurrent == 0 || i==n-1) {
			numOfHitsOneReload = numOfHits;
			cout << "Number of hit targets with one reload: " << numOfHitsOneReload << endl;
		}
	}
	
}
