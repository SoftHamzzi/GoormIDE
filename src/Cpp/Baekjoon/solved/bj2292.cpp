#include <iostream>

using namespace std;

int main(void) {
	int n; cin>>n; --n;
	int six=6;
	int cnt=0;
	
	while(0<n) {
		n -= six; six+=6;
		cnt++;
	}
	cnt++;
	
	cout<<cnt<<endl;
}