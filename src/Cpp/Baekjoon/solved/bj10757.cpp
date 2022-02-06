#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	string a; cin>>a;
	string b; cin>>b;
	
	if(a.length() < b.length())
		swap(a,b);
	
	int aLen = a.length();
	int bLen = b.length();
	
	int aArray[10003];
	int bArray[10003];
	
	// int형 배열에 하나씩 옮겨담기
	stack<int> ans;
	
	for(int i=0;i<aLen;i++) {
		aArray[i+1] = a[i]-'0';
		bArray[i+1+aLen-bLen] = b[i]-'0';
	}
	
	int sum;
	for(int i=aLen;i>0;i--) {
		sum = aArray[i] + bArray[i];
		if(10 <= sum) {
			aArray[i-1]++;
			sum-=10;
		}
		ans.push(sum);
	}
	
	if(aArray[0]==1) {
		ans.push(1);
	}
	
	while(!ans.empty()) {
		cout<<ans.top();
		ans.pop();
	}
	cout<<endl;
}

/*
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(void) {
	char a[10003]={0}; cin>>a;
	char b[10003]={0}; cin>>b;
	char c[10003];
	
	int carry=0;
	int onSum;
	
	int aLen = strlen(a);
	int bLen = strlen(b);
	
	int aNum, bNum;
	
	reverse(a,a+aLen);
	reverse(b,b+bLen);
	
	int maxLen = aLen>bLen ? aLen:bLen;
	for(int i=0;i<maxLen;i++) {
		aNum = a[i]==0 ? 0:a[i]-'0';
		bNum = b[i]==0 ? 0:b[i]-'0';
		
		onSum=aNum+bNum+carry;
		if(10 <= onSum) {
			carry = 1;
			c[i] = onSum-10+'0';
		} else {
			carry = 0;
			c[i] = onSum + '0';
		}
	}
	if(carry==1) {
		c[maxLen] = 1+'0';
	}
	
	int cLen = strlen(c);
	reverse(c,c+cLen);
	for(int i=0;i<cLen;i++) {
		cout<<c[i]-'0';
	}
	cout<<endl;
}
*/