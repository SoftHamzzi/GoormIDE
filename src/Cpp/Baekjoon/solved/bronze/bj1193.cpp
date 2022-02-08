#include <iostream>

using namespace std;

int main(void) {
	int x; cin>>x;
	int d=1;
	int cnt=1;
	
	while(0<x-d) {
		x -= d; d++;
		cnt++;
	}
	int a, b;
	if(cnt%2) {
		b = x;
		a = cnt+1-b;
	} else {
		a = x;
		b = cnt+1-a;
	}
	
	cout<<a<<"/"<<b<<endl;
}