#include <iostream>

using namespace std;

int main(void) {
	int max=-1;
	int index;
	int input;
	for(int i=1;i<=9;i++) {
		cin>>input;
		if(max<input) {
			max = input;
			index = i;
		}
	}
	cout<<max<<"\n"<<index<<"\n";
}