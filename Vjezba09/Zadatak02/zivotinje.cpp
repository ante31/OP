#include "zivotinje.hpp"


int Ptica::brojNogu() {
	return this->noge;
}

string Ptica::vrstaZivotinje() {
	return this->vrsta;
}

void Ptica::setVrsta(string s) {
	this->vrsta = s;
}

void Ptica::setNoge(int n) {
	this->noge = n;
}

int Pauk::brojNogu() {
	return this->noge;
}

string Pauk::vrstaZivotinje() {
	return this->vrsta;
}

void Pauk::setVrsta(string s) {
	this->vrsta = s;
}

void Pauk::setNoge(int n) {
	this->noge = n;
}

Tarantula::Tarantula() {
	setVrsta("Tarantula");
	setNoge(8);
}

Pticar::Pticar() {
	setVrsta("Pticar");
	setNoge(8);
}

Galeb::Galeb() {
	setVrsta("Galeb");
	setNoge(2);
}

Sokol::Sokol() {
	setVrsta("Sokol");
	setNoge(2);
}
