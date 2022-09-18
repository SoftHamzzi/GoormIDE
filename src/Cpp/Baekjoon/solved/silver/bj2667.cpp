#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int table[26][26];
int n;
int aptCnt=0;
int cnt;

void dfs(int y, int x) {
	
	// 밖으로 나갔거나 이미 다녀온 곳일 경우 
	if(y < 1 || n < y || x < 0 || n < x || !table[y][x]) 
		return;
		
	table[y][x] = 0; // 현재 위치를 이미 다녀온 곳으로 
		
	dfs(y,x+1); // 동 
	dfs(y,x-1); // 서 
	dfs(y+1,x); // 남 
	dfs(y-1,x); // 북
	
	cnt++;
}

int main(void) {
	
	cin>>n;
	vector<int> cntVector;
	
	string temp;
	for(int i=1; i<=n; i++) {
		cin>>temp;
		for(int j=1; j<=n; j++) {
			table[i][j] = temp[j-1]-'0';
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(table[i][j]) {
				cnt=0;
				aptCnt++;
				dfs(i,j);
				cntVector.push_back(cnt);
			}
		}
	}
	
	sort(cntVector.begin(), cntVector.end());
	
	cout << aptCnt << endl;
	for(vector<int>::iterator iter=cntVector.begin(); iter!=cntVector.end(); iter++) {
		
		cout << *iter << endl;
		
	}
	
}