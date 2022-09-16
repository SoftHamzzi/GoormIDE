#include <iostream>

using namespace std;

int main(void) {
	
	string s;
	getline(cin,s);
	
	int cnt=0;
	bool isWord = false;
	
	for(int i=0;i<s.size();i++) {
		if(('A'<=s[i] && s[i]<='Z' || 'a'<=s[i] && s[i]<='z') && isWord == false) {
			cnt++;
			isWord = true;
		} else if(s[i]==' '){
			isWord = false;
		}
	}
	cout<<cnt;
}