#include <iostream>

using namespace std;

int countDigit(int n) {
	int i=1; int count=0;
	while(n/i) {
		i*=10;
		count++;
	}
	
	return count;
}

// 변수 선언이 너무 혼잡함
int decompose(int n, int count) {
	int dnum=n;
	int digit;
	int dsum=0;
	int dcount=1;
	
	for(int i=0;i<count-1;i++) {
		dcount*=10;
	}
	
	while(dcount!=0) {
		digit = dnum/dcount;
		dsum += digit;
		
		dnum -= digit*dcount;
		dcount /= 10;
	}
	
	return dsum+n;
}

int main(void) {
	int n; cin>>n;
	int count = countDigit(n);
	
	for(int i=n-(count*9);i<=n;i++) {
		if(decompose(i,count)==n) {
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"0"<<endl;
	return 0;
}