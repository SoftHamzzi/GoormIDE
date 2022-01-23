#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n,m; // n은 카드 갯수, m은 제한 숫자
	cin>>n>>m;
	
	int input;
	vector<int> v;
	for(int i=0;i<n;i++) {
		cin>>input;
		v.push_back(input);
	}
	
	int sum, maxSum=0;
	
	for(int i=0;i<n-2;i++) {
		for(int j=i+1;j<n-1;j++) {
			for(int k=j+1;k<n;k++) {
				sum=v[i]+v[j]+v[k];
				if(sum == m) {
					cout<<m<<endl;
					return 0;
				}
				if(sum <= m && maxSum<sum) {
					maxSum=sum;
				}
			}
		}
	}
	cout<<maxSum<<endl;
}