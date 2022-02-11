#include <iostream>
#include <algorithm>

using namespace std;

bool descCompare(int a, int b) {
	return a>b;
}

int main(void) {
	int n; cin>>n;
	int sum=0;
	int a[50];
	int b[50];
	
	// a와 b배열 입력 받기
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
	}
	
	sort(a,a+n);
	sort(b,b+n,descCompare);
	
	for(int i=0;i<n;i++) {
		sum += a[i]*b[i];
	}
	
	cout<<sum<<endl;
}