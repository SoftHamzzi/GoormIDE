#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int t; cin>>t;
	
	int s,e;
	int d;
	int j;
	int cnt=0;
	
	for(int i=0;i<t;i++) {
		cin>>s>>e;
		d = e-s;
		cnt=0;
		
		if(d<4) {
			cout<<d<<endl;
			continue;
		}
		
		// 최대 제곱 구하기
		int squ=1;
		while(d < pow(squ,2) || pow(squ+1,2) <= d) {
			squ++;
		}
		cnt += 2*(squ-1)+1;
		d-=pow(squ,2);
		
		// 거리에서 제곱을 빼고 남은 거리를 처리하기
		int j = squ;
		while(d!=0) {
			if(0<=d-j) {
				d -= j;
				cnt++;
			} else {
				j--;
			}
		}
		cout<<cnt<<endl;
	}
}