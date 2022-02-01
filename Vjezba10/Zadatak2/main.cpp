/*
Napišite template klasu Stack. Implementirajte funkcije članove za operacije
push, pop i is_empty.
Napomena: Odvojite sučelje i implementaciju u različite .cpp i .h datoteke.
*/
#include "starck.h"
#include <iostream>

using namespace std;

int main() {
	Stack<int> stack(4);

	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.print();
	stack.pop();
	cout << endl;
	if (stack.isEmpty())
		cout << "Not empty";
	else
		cout << "Is empty";

}
