// 메모이제이션 방식
#include <iostream>

using namespace std;

int memo[1000]={0,1,1};

int fibo(int c, int n) {
	if(3<=c && memo[c]!=0) return memo[c];
	else if(c<3) return memo[c];
	
	return memo[c] = fibo(c-2,n) + fibo(c-1,n);
}

int main(void) {
	int n; cin>>n;
	
	for(int i=0;i<n;i++) {
		cout<<fibo(i,n)<<" ";
	}
}

/*
#include <iostream>

using namespace std;

int fibo(int n) {
	if(n==0) return 0;
	else if(n==1 || n==2) return 1;
	
	return fibo(n-2)+fibo(n-1);
}

int main(void) {
	int n; cin>>n;
	
	cout<<fibo(n)<<"\n";
}
*/