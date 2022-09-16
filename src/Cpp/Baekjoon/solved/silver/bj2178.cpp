#include <iostream>
#include <cstdlib>

using namespace std;

int n,m;

int maze[101][101];
int table[101][101];

void dfs(int y, int x, int back) {

	if(x<1 || m<x || y<1 || n<y || !maze[y][x]) { // 밖으로 나가버렸거나, 벽을 만났을 경우 
		return;
	}
	
	if(back+1 >= table[y][x] && table[y][x]!=0) {
		return;
	}
	else
		table[y][x] = back+1;
	
	dfs(y,x+1,table[y][x]); // 동
	dfs(y,x-1,table[y][x]); // 서
	dfs(y+1,x,table[y][x]); // 남
	dfs(y-1,x,table[y][x]); // 북
	
}

int main(void) {
	
	cin>>n>>m;
	
	string input;
	for(int i=1; i<=n; i++) {
		cin>>input;
		for(int j=0; j<input.length(); j++) {
			maze[i][j+1] = input[j]-'0';
		}
	}
	
	dfs(1,1,0);
	
	cout<<table[n][m]<<endl;
}