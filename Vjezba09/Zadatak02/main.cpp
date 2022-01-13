#include "zivotinje.hpp"

int main() {

	Sokol sokol;
	Tarantula tarantula;

	Zivotinja* zivotinje[2];
	int len = sizeof(zivotinje) / sizeof(Zivotinja);

	zivotinje[0] = new Sokol;
	zivotinje[1] = new Tarantula;

	Brojac brojac;


	for (int i = 0; i < len; i++) {
		brojac.zivotinjaPrint(zivotinje[i]);
	}

	brojac.NogePrint();
}
