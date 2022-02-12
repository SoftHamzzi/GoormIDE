#include <iostream>

using namespace std;

int main(void) {
	int x,y,w,h; cin>>x>>y>>w>>h;
	
	int yd = h-y>y ? y:h-y;
	int xd = w-x>x ? x:w-x;
	int rd = yd>xd ? xd:yd;
	cout<<rd<<endl;
}