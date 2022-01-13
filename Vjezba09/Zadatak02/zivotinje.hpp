
#include <iostream>
#include <vector>

using namespace std;

class Zivotinja {
public:
	virtual int brojNogu() = 0;
	virtual string vrstaZivotinje() = 0;
};


//PAUKOVI
class Pauk : public Zivotinja {
	string vrsta;
	int noge;

public:
	int brojNogu();
	string vrstaZivotinje();
	void setVrsta(string s);
	void setNoge(int n);
};

class Tarantula : public Pauk {
public:
	Tarantula();
};

class Pticar : public Pauk {
public:
	Pticar();
};


//PTICE
class Ptica : public Zivotinja {
	string vrsta;
	int noge;

public:
	int brojNogu();
	string vrstaZivotinje();
	void setVrsta(string s);
	void setNoge(int n);
};

class Galeb : public Ptica {
public:
	Galeb();
};

class Sokol : public Ptica {
public:
	Sokol();
};

class Brojac {
private:
	int legs = 0;
public:
	void zivotinjaPrint(Zivotinja* zivotinja) {
		cout << "Dodan: " << zivotinja->vrstaZivotinje() << endl;
		this->legs += zivotinja->brojNogu();
	};

	void NogePrint() {
		cout<< this->legs<<endl;
	}
};
