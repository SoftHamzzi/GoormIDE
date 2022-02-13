#include <iostream>
#include <cmath>

using namespace std;

int cnt=-1;
int result=-1;
int r,c;

void recursion(int x1, int y1, int x2, int y2) {
	if(x1 == x2 && y1 == y2) {
		cout<<"d"<<endl;
		cnt++;
		if(x1-1 == c && y1-1 == r) {
			result=cnt;
		}
		return;
	}
	
	if(result!=-1) {
		cout<<result<<endl;
		exit(-1);
	}
	
	recursion(x1,y1, x1+(x2-x1)/2,y1+(y2-y1)/2);
	recursion(x1+((x2-x1+1)/2),y1, x2,y1+(y2-y1)/2);
	recursion(x1,y1+((y2-y1+1)/2), x1+(x2-x1)/2,y2);
	recursion(x1+((x2-x1+1)/2),y1+((y2-y1+1)/2), x2,y2);
}

int main(void) {
	int n; cin>>n>>r>>c;
	
	recursion(1,1,pow(2,n),pow(2,n));
}