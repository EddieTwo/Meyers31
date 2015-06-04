#include <iostream>
#include <vector>

#include <functional>
#include <algorithm>

using namespace std;
using filterContainer = vector<function<bool(int)>>;

filterContainer filters;
vector<int> vi = { 12, 2, 89, -9, 0, };

void vectorSpecial(vector<int>& vr)
{
	int i = 5;
	int& ri = i;
	vr.push_back(ri);
}

void addDivisorFilter()
{
	auto divisor = 5;
	filters.emplace_back([divisor = divisor](int value) { return value % divisor == 0; });
}

int main()
{
	//             
	vi.push_back(79);
	vectorSpecial(vi);

	for (auto foo : vi)
		cout << foo << "\t";
	cout << endl;

	for (auto& foo : vi)
		foo *= 5;

	// dangling references in closures
	filters.emplace_back( [](int value) {return value % 5 == 0; });
	addDivisorFilter();
	for (auto& foo : filters)
		cout << "test" << endl;

	cout << all_of(begin(vi), end(vi), filters[0]) << endl;
	int divisor = 5;
	cout << all_of(begin(vi), end(vi), [&divisor](int value) { return value % divisor == 0; }) << endl;

	// this pointer

	return 0;
}