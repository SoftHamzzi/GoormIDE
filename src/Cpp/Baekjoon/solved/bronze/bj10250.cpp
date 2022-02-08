#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int t; cin>>t;
	int h,w,n;
	
	int floor, unit;
	
	for(int i=0;i<t;i++) {
		cin>>h>>w>>n;
		
		floor = n - (n/h)*h;
		if(!floor) floor = h;
		unit = ceil((double)n/h);
		
		cout<<floor;
		cout.width(2);
		cout.fill('0');
		cout<<unit<<endl;
	}
}