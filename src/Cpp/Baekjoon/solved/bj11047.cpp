#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int n,k;
	int temp;
	int coin=0;
	cin>>n>>k;
	stack<int> value;
	
	for(int i=0;i<n;i++) {
		cin>>temp;
		value.push(temp);
	}
	
	while(!value.empty()) {
		if(k<0) break;
		while(0 <= k-value.top()) {
			k -= value.top();
			coin++;
		}
		value.pop();
	}
	
	cout<<coin<<endl;
	return 0;
}