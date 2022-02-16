// 분할정복 + 재귀
#include <iostream>
#include <cmath>

using namespace std;

int n,r,c;
int cnt=0;

void recursion(int y, int x, int len) {
	if(r==y && c==x) {
		cout<<cnt<<endl;
		return;
	}
	
	if(y <= r && r < y+len && x <= c && c < x+len) {
		recursion(y,x,len/2);
		recursion(y,x+(len/2),len/2);
		recursion(y+(len/2),x,len/2);
		recursion(y+(len/2),x+(len/2),len/2);
	} else {
		cnt += len*len;
		return;
	}
}

int main(void) {
	cin>>n>>r>>c;
	
	recursion(0,0,pow(2,n));
}