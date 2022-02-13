// 유기농 배추 (계획에 오차있어서 코드 개판됨)
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _coordinate {
	int x;
	int y;
} coordinate;

int compare(coordinate cabbage1, coordinate cabbage2) {
	if(cabbage1.y == cabbage2.y) {
		return cabbage1.x < cabbage2.x;
	} else {
		return cabbage1.y < cabbage2.y;
	}
}

// 주위를 탐색했을때 아무것도 없다면 0을 반납, 자연수를 반납했다면 그 숫자를 반납
int search(int (*farm)[50], int m, int n, int x, int y) {
	// 위
	if(1<=y && 0<farm[y-1][x]) {
		return farm[y-1][x];
	}
	// 오른쪽
	if(x<=m-2 && 0<farm[y][x+1]) {
		return farm[y][x+1];
	}
	// 아래
	if(y<=n-2 && 0<farm[y+1][x]) {
		return farm[y+1][x];
	}
	// 왼쪽
	if(1<=x && 0<farm[y][x-1]) {
		return farm[y][x-1];
	}
	
	// 주위에 아무것도 없음
	return 0;
}

void resetFarm(int (*farm)[50], int m, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			farm[i][j] = 0;
		}
	}
}

int main(void) {
	int t; cin>>t; // 테스트 케이스 갯수
	int m,n; // 가로길이 m, 세로길이 n
	int k; // 배추 갯수
	int farm[50][50];
	coordinate cabbage[2500];
	
	int ix,iy;
	int x,y;
	int rNum;
	int cnt=0;
	// 테스트 케이스만큼 반복
	for(int i=0;i<t;i++) {
		cin>>m>>n;
		cin>>k;
		
		// 배추 갯수만큼 배추 좌표 입력
		for(int j=0;j<k;j++) {
			cin>>ix>>iy;
			cabbage[j].x=ix;
			cabbage[j].y=iy;
			farm[iy][ix]=-1;
		}
		
		sort(&cabbage[0], &cabbage[k], compare);
		
		for(int l=0;l<k;l++) {
			// 0을 받으면 주위에 아무것도 없다는 뜻이니 cnt를 넣는다.
			// 자연수를 받으면 그 자연수를 넣는다.
			x = cabbage[l].x;
			y = cabbage[l].y;
			
			rNum = search(farm,m,n,x,y);
			if(rNum == 0) {
				farm[y][x] = ++cnt;
			} else {
				farm[y][x] = rNum;
			}
		}
		cout<<cnt<<"\n";
		
		cnt=0;
		resetFarm(farm,m,n);
	}
}