#include <iostream>
#include <string>
#include <map>

using namespace std;

int isDigit(string s) {
	if(0<=s[0]-'0' && s[0]-'0'<=9)
		return 1;
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m; cin>>n>>m; // 도감 안의 갯수, 문제 갯수
	string dex[100001];
	map<string,int> dexmap;
	
	string input;
	for(int i=1;i<=n;i++) {
		cin>>input;
		dex[i] = input;
		dexmap.insert({input,i});
	}
	
	for(int i=1;i<=m;i++) {
		cin>>input;
		if(isDigit(input))
			cout<<dex[stoi(input)]<<"\n";
		else
			cout<<dexmap[input]<<"\n";
	}
}