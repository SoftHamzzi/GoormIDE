#include <iostream>

using namespace std;

int fac(int n) {
	if(n==0 || n==1) {
		return 1;
	}
	
	return n*fac(n-1);
}

int main(void) {
	int n; cin>>n;
	
	cout<<fac(n)<<"\n";
}