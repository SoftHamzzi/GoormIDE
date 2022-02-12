#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	// 끊어진 기타줄 갯수 n<=100, 기타줄 브랜드 m<=50
	int n,m; cin>>n>>m;
	int total=0;
	
	double price[3][50]; // 0열 패키지, 1열 낱개 , 2열 패키지 가성비
	
	for(int i=0;i<m;i++) {
		cin>>price[0][i]>>price[1][i];
		price[2][i] = price[0][i]/6;
	}
	
	int min[2] = {1,0};
	for(int i=1;i<=2;i++) {
		for(int j=0;j<m;j++) {
			if(price[min[0]][min[1]] > price[i][j]) {
				min[0]=i,min[1]=j;
			}
		}
	}
	
	// min[0]에서 i가 1이면 낱개 가격, 2면 패키지 가성비
	if(min[0]==1) { // 낱개인 경우
		total += m*price[min[0]][min[1]];
		// 가장 싼것이 낱개인 경우 모두 사버리고 끝냄
	}
	else if(min[0]==2) { // 패키지인 경우
		int x = floor((double)n/6); // 사야할 기타줄이 음수가 안되게 살 최대 패키지 갯수.
		
		total += x*price[0][min[1]];
		n -= x*6;
		
		if(0<n) { // 아직도 기타줄을 더 사야한다면
			// 먼저 낱개 가격중에서 가장 싼 것을 찾는다.
			int emin = price[1][0];
			for(int i=0;i<m;i++) {
				if(emin > price[1][i]) emin = price[1][i];
			}
			
			// 낱개와 패키지 중에서 싼 것을 찾아서 그걸로 다 산다
			if(price[0][min[1]] > emin * n) { // 20>16
				total += emin * n;
			} else {
				total += price[0][min[1]];
			}
		}
	}
	cout<<total<<endl;
}