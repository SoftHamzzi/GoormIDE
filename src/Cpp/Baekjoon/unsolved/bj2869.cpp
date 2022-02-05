#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int a,b,v; cin>>a>>b>>v;
	
	cout<<fixed;
	cout.precision(0);
	cout<<ceil((double)(v-b)/(a-b))<<endl;
}