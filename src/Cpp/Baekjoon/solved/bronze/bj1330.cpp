#include <iostream>

using namespace std;

int main(void) {
	int a,b; cin>>a>>b;
	
	string s;
	
	if(a>b) {
		s = ">";
	} else if(a==b) {
		s = "==";
	} else {
		s = "<";
	}
	cout<<s;
}