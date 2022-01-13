#include <iostream>

using namespace std;

class brojac {
public:
	int brojac = 0;
};

class zivotinja : public brojac {
public:
	int *pBrojac = *brojac;
};

class kukac : public zivotinja {
public:
	int* ppBrojac = pBrojac;
};

class pauk : public zivotinja {
public:
	int* ppBrojac = pBrojac;
};

class ptica : public zivotinja {
public:
	int* ppBrojac = pBrojac;
};

class zohar : public kukac {
	int* pppBrojac = ppBrojac;
public:
	zohar() {
		pppBrojac += 8;
	}
};

class tarantula : public pauk {
	int* pppBrojac = ppBrojac;
public:
	tarantula() {
		pppBrojac += 6;
		cout << "dodana tarantula"<<endl;
	}
};

class vrabac : public ptica {
public:
	int* pppBrojac = ppBrojac;

	vrabac() {
		pppBrojac += 2;
	}
};