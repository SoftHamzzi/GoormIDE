#include <iostream>

using namespace std;

typedef struct _count {
	int zero;
	int one;
} count;

count memo[41] = {};

void fibonacci(int n) {
	if(n<=2) {
		return;
	}
	
	if(memo[n].zero || memo[n].one) {
		return;
	} else {
		fibonacci(n-1);
		fibonacci(n-2);
		memo[n].zero = memo[n-1].zero + memo[n-2].zero;
		memo[n].one = memo[n-1].one + memo[n-2].one;
		return;
	}
	return;
}

int main(void) {
	int t; cin>>t;
	memo[0].zero++;
	memo[1].one++;
	memo[2].zero++; memo[2].one++;
	
	int input;
	for(int i=0;i<t;i++) {
		cin>>input;
		fibonacci(input);
		cout<<memo[input].zero<<" "<<memo[input].one<<"\n";
	}
}