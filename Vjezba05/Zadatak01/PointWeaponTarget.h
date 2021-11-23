#ifndef POINTWEAPONTARGET_H
#define POINTWEAPONTARGET_H

#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
	double x;
	double y;
	double z;

	Point setToZero(Point p);
	Point setToRandom(Point p, double a, double b);
	double* getValueX(Point p);
	double* getValueY(Point p);
	double* getValueZ(Point p);
	double distance2D(Point p1, Point p2);
	double distance3D(Point p1, Point p2);
};

class Weapon : public Point {
	const int a = 0, b = 50;
public:
	Point weaponPoint = Point::setToRandom(weaponPoint, a, b);
	int ammoCurrent = 6;
	int ammoCapacity = 6;
	void shoot(Weapon w);
	void reload(Weapon w);
};

class Target : public Point {
	const int a = 0, b = 50;
	public:
		Point lowerLeft = Point::setToRandom(lowerLeft, a, b);
		Point upperRight = Point::setToRandom(upperRight, lowerLeft.z, b);
		bool hitStatus = false;
};

void action(Weapon w, Target* t, int n);
#endif
