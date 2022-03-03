#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s; cin>>s;
	
	int total = 0;
	int minus=0; // 0이면 +, 1이면 -
	
	int start=-1;
	int end=-1;
	for(int i=0;i<s.size();i++) {
		// 숫자일때
		if(0<=s[i]-'0' && s[i]-'0'<=9 && start == -1) {
			start = i;
		} else if(s[i]=='-' || s[i]=='+') { // 연산자일때
			end = i-1;
			if(minus == 0) {
				total += stoi(s.substr(start,end-start+1));
				if(s[i] == '-')
					minus = 1;
			} else {
				total -= stoi(s.substr(start,end-start+1));
			}
			start = -1;
			end = -1;
		}
	}
	
	// 연산자 없었던 뒷부분 마감
	end = s.size() - 1;
	
	if(minus == 0) {
		total += stoi(s.substr(start,end-start+1));
	} else {
		total -= stoi(s.substr(start,end-start+1));
	}
	
	cout<<total<<"\n";
}