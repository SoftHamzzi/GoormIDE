// 유기농 배추 (계획에 오차있어서 코드 개판됨)
#include <iostream>

using namespace std;

typedef struct _coordinate {
	int x;
	int y;
} coordinate;

void dfs(int (*farm)[50], int m, int n, int x, int y) {
	// 경계를 벗어났거나, 해당 장소가 0이라면 돌아감
	if(x<0 || m<=x || y<0 || n<=y || !farm[y][x]) {
		return;
	}
	
	farm[y][x]=0;
	// 위쪽
	dfs(farm,m,n,x,y-1);
	// 오른쪽
	dfs(farm,m,n,x+1,y);
	// 아래쪽
	dfs(farm,m,n,x,y+1);
	// 왼쪽
	dfs(farm,m,n,x-1,y);
		
	return;
}

/*
for(int a=0;a<n;a++) {
	for(int b=0;b<m;b++) {
		cout<<farm[a][b];
	}
	cout<<"\n";
}
*/

int main(void) {
	int t; cin>>t; // 테스트 케이스 갯수
	int m,n; // 가로길이 m, 세로길이 n
	int k; // 배추 갯수
	int farm[50][50];
	coordinate cabbage[2500];

	int inputX,inputY;
	int cnt=0;
	// 테스트 케이스만큼 반복
	for(int i=0;i<t;i++) {
		cin>>m>>n;
		cin>>k;
		
		// 배추 갯수만큼 배추 좌표 입력
		for(int j=0;j<k;j++) {
			cin>>inputX>>inputY;
			cabbage[j].x=inputX;
			cabbage[j].y=inputY;
			farm[inputY][inputX]=1;
		}
		
		// 배추 갯수만큼 DFS 돌리기
		for(int j=0;j<k;j++) {
			// 배추 위치를 살펴봤을때 1일 경우만 dfs를 돌림
			if(farm[cabbage[j].y][cabbage[j].x]) {
				dfs(farm, m, n, cabbage[j].x, cabbage[j].y);
				cnt++;
			}
		}
		cout<<cnt<<"\n";
		cnt=0;
	}
}