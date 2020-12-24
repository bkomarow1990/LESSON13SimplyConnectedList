#include <iostream>
#include "FwdList.h"
using namespace std;
int main() {
//	FwdList<int> f1;
//	f1.pushFront(10);
//	f1.pushFront(5);
//	f1.pushFront(8);
//	f1.pushFront(7);
//	f1.print();
//	//f1.eraseFront();
//	f1.eraseAfter(10);
//	f1.print();
//	f1.pushAfter(5,122);
//	cout << "Before: " << endl;
//	f1.print();
////	f1.eraseAfter(8);
//
//	cout << "Erase tail" << endl;
//	f1.eraseTail();
//	f1.print();
//	cout << "======================" << endl;
//	f1.print();
//	FwdList<int> f2 = f1;
//	cout << "f2: " << endl;
//	//f2.addTail(2);
//	f2.print();
//	cout << "Added tail 33" << endl;
//	f1.addTail(33);
//	f1.print();
////	f2.print();
//	cout <<boolalpha<< (f1 == f2 ) << endl;
	//cout << "New" << endl;
	//FwdList<int>f3;
	//f3.addTail(228);
	//f3.addTail(228);
	//f3.addTail(228);
	//f3.addTail(228);
	//f3.print();
	FwdList<int>f1;
	f1.addTail(666);
	f1.addTail(228);
	f1.addTail(1337);
	f1.addTail(666);
	f1.addTail(666);
	f1.addTail(999);
	f1.addTail(22);
	f1.addTail(666);
	f1.print();
	//f1.pushAfter(6636,888);
	//f1.deleteElemWithData(666);
	cout<<f1.findAndReplace(666,1111)<<endl;
	f1.print();
	f1.reverseList();
	f1.print();
	return 0;
}