#include <iostream>
#include <forward_list>
using namespace std;
template <typename T>
void print(const T& container) {
	for (auto& elem: container)
	{
		cout << elem << " ";
	}
	cout << endl;
}
int main() {
	forward_list<int> fl{ 10,23,150,500 };
	cout <<boolalpha<< fl.empty() << endl;

	fl.front() = 111;
	print(fl);
	fl.insert_after(fl.begin(), { 7,8,9 });
	print(fl);
	auto it = find(fl.begin(), fl.end(), 150);
	if (it!=fl.end())
	{
		fl.insert_after(it, 777);
	}
	return 0;
}