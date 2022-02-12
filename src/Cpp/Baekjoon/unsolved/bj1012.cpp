// 유기농 배추
#include <iostream>

using namespace std;

// 주위를 탐색했을때 아무것도 없다면 0을 반납, 자연수를 반납했다면 그 숫자를 반납
int search(int (*farm)[50], int m, int n, int x, int y) {
	// 위
	if(1<=y && farm[x][y-1]) {
		return farm[x][y-1];
	}
	// 오른쪽
	if(x<=m-2 && farm[x+1][y]) {
		return farm[x+1][y];
	}
	// 아래
	if(y<=n-2 && farm[x][y+1]) {
		return farm[x][y+1];
	}
	// 왼쪽
	if(1<=x && farm[x-1][y]) {
		return farm[x-1][y];
	}
	
	// 주위에 아무것도 없음
	return 0;
}

void resetFarm(int (*farm)[50], int m, int n) {
	for(int a=0;a<n;a++) {
		for(int b=0;b<m;b++) {
			farm[a][b] = 0;
		}
	}
}

int main(void) {
	int t; cin>>t; // 테스트 케이스 갯수
	int m,n; // 가로길이 m, 세로길이 n
	int k; // 배추 갯수
	int farm[50][50];
	
	int x,y;
	int rNum;
	int cnt=0;
	// 테스트 케이스만큼 반복
	for(int i=0;i<t;i++) {
		cin>>m>>n;
		cin>>k;
		
		// 배추 갯수만큼 배추 좌표 입력
		for(int j=0;j<k;j++) {
			cin>>x>>y;
			farm[x][y]=-1;
			
			// 0을 받으면 주위에 아무것도 없다는 뜻이니 cnt를 넣는다.
			// 자연수를 받으면 그 자연수를 넣는다.
			rNum = search(farm,m,n,x,y);
			if(rNum == 0) {
				farm[x][y] = ++cnt;
			} else {
				farm[x][y] = rNum;
			}
		}
		cout<<cnt<<"\n";
		cnt=0;
		resetFarm(farm,m,n);
	}
}