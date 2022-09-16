#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> avail(100);

int table[100][100];
int shortcut[12][3];

int main(void) {
	int t, dest; cin>>t>>dest;
	
	avail.push_back(0); avail.push_back(dest);
	
	int scCnt=0;
	// 입력 값을 받고 avail vector에 입력 값들 걸러서 넣기
	while(t--) {
		int s,e,dist; cin>>s>>e>>dist;
		
		if(dest<e || e-s <= dist)
			continue;
		
		shortcut[scCnt][0] = s;
		shortcut[scCnt][1] = e;
		shortcut[scCnt][2] = dist;
		scCnt++;
		
		avail.push_back(s);
		avail.push_back(e);
	}
	
	// vector를 이용해 index로 접근 가능한 set 만들기.
	sort(avail.begin(), avail.end());
	avail.erase(unique(avail.begin(),avail.end()),avail.end());
	
	// 잘못 생각했던 부분을 야매로 매꾸기
	for(int i=0;i<scCnt;i++) {
		for(int j=0;j<2;j++) {
			for(int k=0;k<avail.size();k++) {
				if(shortcut[i][j] == avail[k]) {
					shortcut[i][j] = k;
					break;
				}
			}
		}
	}
	
	// 테이블 준비하기
	for(int i=0;i<avail.size()-1;i++) {
		for(int j=i+1;j<avail.size();j++) {
			table[i][j] = avail[j] - avail[i];
		}
	}
	
	for(int i=0;i<scCnt;i++) {
		int s = shortcut[i][0];
		int e = shortcut[i][1];
		int dist = shortcut[i][2];
		if(table[s][e] > dist)
			table[s][e] = dist;
	}
	
	// 다익스트라 시작
	for(int i=1;i<avail.size();i++) {
		for(int j=i+1;j<avail.size();j++) {
			int nextDist = table[0][i] + table[i][j];
			if(nextDist < table[0][j])
				table[0][j] = nextDist;
		}
	}
	
	cout<<table[0][avail.size()-1]<<endl;
}