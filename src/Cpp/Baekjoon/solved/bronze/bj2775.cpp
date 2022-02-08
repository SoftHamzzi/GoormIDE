#include <iostream>

using namespace std;

int main(void) {
	int arr[14];
	
	int t; cin>>t;
	
	for(int f=0;f<t;f++) {
		int k,n; cin>>k>>n;
	
		for(int i=0;i<n;i++) {
			arr[i]=i+1;
		}
	
		for(int i=0;i<k;i++) {
			for(int j=1;j<n;j++) {
			arr[j]+=arr[j-1];
			}
		}
		cout<<arr[n-1]<<endl;
	}
}