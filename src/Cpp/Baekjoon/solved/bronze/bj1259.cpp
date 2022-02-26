#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string input;
	int len;
	int isNo;
	
	while(1) {
		isNo=0;
		cin>>input;
		if(input[0]-'0'==0)
			break;
		
		// 여기서부터 시작
		len = input.size();
		for(int i=0;i<len/2;i++) {
			if(input[i] != input[len-i-1]) {
				cout<<"no\n";
				isNo = 1;
				break;
			}
		}
		if(isNo)
			continue;
		
		cout<<"yes\n";
	}
}