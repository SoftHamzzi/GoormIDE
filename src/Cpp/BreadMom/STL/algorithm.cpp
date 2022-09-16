#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <vector>

using namespace std;

void myfunction(int& n) {
	cout<< n <<" ";
}

bool down(const int& a, const int& b) {
	return a>b;
}

int main(void) {
	
	vector<int> v = {3,1,2,7,5};
	
	iter_swap(v.begin(), v.begin()+2);
	for_each(v.begin(), v.end(), myfunction);
	cout<<endl;
	
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myfunction);
	cout<<endl;
	
	sort(v.begin(), v.end(), down);
	for_each(v.begin(), v.end(), myfunction);
}