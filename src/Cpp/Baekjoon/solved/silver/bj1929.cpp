#include <iostream>

using namespace std;

int main(void) {
	int m,n; cin>>m>>n;
	
	int notPrime[1000001]={1,1};
	
	int j;
	for(int i=2;i<=n;i++) {
		// 소수가 아니라면
		if(notPrime[i])
			continue;
		
		// 소수면서 m보다 크거나 같다면
		if(!notPrime[i] && m<=i) {
			cout<<i<<"\n";
		}
		
		// 해당 수의 배수들을 모두 소수아님으로 지정
		j=2;
		while(i*j <= n) {
			notPrime[i*j] = 1;
			j++;
		}
	}
}