#include "formula.h"


timer timer::operator += (const timer t)
{
	this->h += t.h;
	this->m += t.m;
	this->s += t.s;
	return *this;
}

timer timer::operator /= (int v)
{
	double time = 3600 * this->h + 60 * this->m + this->s;
	time /= v;

	this->h = time / 3600;
	this->m = (time - h * 3600) / 60;
	this->s = time - h * 3600 - m * 60;
	return *this;
}

ostream& operator<<(ostream& output, const timer t) {
	output << t.h << ":" << t.m << ":" << t.s << "\n";
	return output;
}

bool timer::operator<(const timer& other) {
	double time1 = 3600 * this->h + 60 * this->m + this->s;
	double time2 = 3600 * other.h + 60 * other.m + other.s;
	return ((time1 < time2) ? 1 : 0);
}

timer timer::operator=(const timer& other) {
	h = other.h;
	m = other.m;
	s = other.s;
	return *this;
}

double timer::operator - (const timer& other)
{
	double time1 = 3600 * this->h + 60 * this->m + this->s;
	double time2 = 3600 * other.h + 60 * other.m + other.s;
	return time1 - time2;
}

int timer::getH(timer t) {
	return h;
}
int timer::getM(timer t) {
	return m;
}
int timer::getS(timer t) {
	return s;
}


penalty penalty::operator()(timer t)
{
	int hours = t.getH(t);
	int minutes = t.getM(t);
	int seconds = t.getS(t);
	
	h += hours;
	m += minutes;
	s += seconds;
	return *this;
}
