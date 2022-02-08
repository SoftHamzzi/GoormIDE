#include <iostream>

using namespace std;

int main(void) {
	int n; cin>>n;
	
	while(1<n) {
		for(int i=2;i<=n;i++) {
			if(n%i==0) {
				n/=i;
				cout<<i<<endl;
				break;
			}
		}
	}
}