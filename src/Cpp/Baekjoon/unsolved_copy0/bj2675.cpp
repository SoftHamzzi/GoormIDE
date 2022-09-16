#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin>>t; // 테스트 케이스
	
	int r;
	string s;
	// 테스트 케이스만큼 반복
	for(int i=0;i<t;i++) {
		cin>>r>>s;
		for(int j=0;j<s.size();j++) {
			for(int k=0;k<r;k++) {
				cout<<s[j];
			}
		}
		cout<<"\n";
	}
}