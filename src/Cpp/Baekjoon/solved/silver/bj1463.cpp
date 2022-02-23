#include <iostream>

using namespace std;

int memo[1000000]={0,0}; // 메모이제이션

int recursion(int x) {
	int arr[3]; // 비교용 배열
	if(x == 1) { // x가 1이 됐다면
		return 0;
	}
	
	if(memo[x]!=0) { // 한번 왔다갔었다면
		return memo[x];
	}
	
	if(x%3==0 && x%2 == 0) { // 3과 2로 모두 나눠진다면
		arr[0] = recursion(x/3);
		arr[1] = recursion(x/2);
		arr[2] = recursion(x-1);
		
		int min = arr[0];
		for(int i=1;i<3;i++) {
			if(min>arr[i])
				min = arr[i];
		}
		
		return memo[x] = min+1;
	}
	else if(x%3==0) { // 3으로만 나눠지는 경우
		arr[0] = recursion(x/3);
		arr[1] = recursion(x-1);
		if(arr[0]>arr[1]) return memo[x] = arr[1]+1;
		else return memo[x] = arr[0]+1;
		
		return memo[x] = recursion(x/3) + 1;
	} else if(x%2==0) { // 2로만 나눠지는 경우
		arr[0] = recursion(x/2);
		arr[1] = recursion(x-1);
		if(arr[0]>arr[1]) return memo[x] = arr[1]+1;
		else return memo[x] = arr[0]+1;
	} else { // 무엇으로도 나누어지지 않는다면
		return memo[x] = recursion(x-1) + 1;
	}
}

int main(void) {
	int x; cin>>x;
	cout<<recursion(x)<<endl;
}