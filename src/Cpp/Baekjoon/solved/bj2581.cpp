#include <iostream>

using namespace std;



int main(void) {
	int m,n; cin>>m>>n;
	int min=-1;
	int sum=0;
	int notPrime[10002]={1,1};
	
	int j;
	for(int i=2;i<=n;i++) {
		// 소수가 아니라면
		if(notPrime[i])
			continue;
		
		// 소수면서 m보다 크거나 같다면
		if(!notPrime[i] && m<=i) {
			if(min==-1) {
				min=i;
			}
			sum += i;
		}
		
		// 해당 수의 배수들을 모두 소수아님으로 지정
		j=2;
		while(i*j <= n) {
			notPrime[i*j] = 1;
			j++;
		}
	}
	
	if(min==-1)
		cout<<-1<<endl;
	else {
		cout<<sum<<endl;
		cout<<min<<endl;
	}
}