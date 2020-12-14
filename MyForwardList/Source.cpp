#include <iostream>
#include "FwdList.h"
using namespace std;
int main() {
	FwdList<int> f1;
	f1.pushFront(10);
	f1.pushFront(5);
	f1.pushFront(8);
	f1.pushFront(7);
	f1.print();
	//f1.eraseFront();
	f1.eraseAfter(10);
	f1.print();
	f1.pushAfter(5,122);
	f1.print();
	return 0;
}