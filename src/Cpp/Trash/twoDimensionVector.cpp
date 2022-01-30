#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int*> v;
	
	v.push_back(1);
	
	cout<<v[0][0]<<endl;
}