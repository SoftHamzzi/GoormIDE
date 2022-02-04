#include <iostream>

using namespace std;

int main(void) {
	int a,b,c; cin>>a>>b>>c;
	int ep = (int)((double)a/(c-b)) + 1;
	int r = 0<ep ? ep:-1;
	
	cout<<r<<endl;
}