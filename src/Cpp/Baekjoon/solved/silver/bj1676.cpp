#include <iostream>

using namespace std;

int main(void) {
	int n; cin>>n;
	int total=0;
	int temp;
	for(int i=n;i>0;i--) {
		temp = i;
		while(temp%5==0) {
			total++;
			temp /= 5;
		}
	}
	
	cout<<total<<endl;
}