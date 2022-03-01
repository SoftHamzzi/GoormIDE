#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin>>t;
	int input1, input2;
	
	for(int i=0;i<t;i++) {
		cin>>input1>>input2;
		cout<<input1+input2<<"\n";
	}
}