#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int n; cin>>n;
	string text[50];
	
	for(int i=0;i<n;i++) {
		cin>>text[i];
	}
	
	int len = text[0].length();
	char part;
	for(int i=0;i<len;i++) {
		part = text[0][i];
		for(int j=0;j<n;j++) {
			if(part != text[j][i]) {
				cout<<"?";
				break;
			} else {
				if(j==n-1) {
					cout<<part;
				}
			}
		}
	}
	return 0;
}