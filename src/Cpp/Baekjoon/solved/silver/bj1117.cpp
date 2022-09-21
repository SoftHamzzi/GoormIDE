#include <iostream>

using namespace std;

int main(void) {
	
	long long left, right, mid; 
	long long w,h,f,c,x1,y1,x2,y2;
	
	cin>>w>>h>>f>>c>>x1>>y1>>x2>>y2;
	
	long long total = w*h;
	
	left = 2*(c+1);
	right = c+1;
	
	if(w-f >= f)
		mid = f;
	else
		mid = w-f;
		
	if( x2 < mid ) {
		total -= (x2-x1) * (y2-y1) * left;
	} else if(mid <= x1 ) {
		total -= (x2-x1) * (y2-y1) * right;
	} else {
		
		left = (mid-x1)*(y2-y1)*left;
		right = (x2-mid)*(y2-y1)*right;
		
		total -= left + right;
	
	}
	
	cout << total << endl;
}