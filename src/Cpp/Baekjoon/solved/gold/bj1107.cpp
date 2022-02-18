// 브루트포스로 풀기
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int n,m;
int broken[10];

int check(int num) {
	string sn = to_string(num);
	for(int i=0;i<sn.size();i++) {
		if(broken[sn[i]-'0']) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	cin>>n>>m;
	
	int input;
	for(int i=0;i<m;i++) {
		cin>>input;
		broken[input]=1;
	}
	
	int min=abs(n-100);
	for(int i=0;i<1000000;i++) {
		if(check(i) && min > abs(n-i)+to_string(i).size()) {
			min = abs(n-i)+to_string(i).size();
		}
	}
	
	cout<<min<<endl;
}

/* 포기
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int broken[10];

int n,m;
int digit=0; // 자릿수
string sn = to_string(n);

void solve(int d) {
	int number1 = sn[digit-d]-'0';
	int number2 = sn[digit-d+1]-'0';
	int rn[3];
	int cn[3];
	
	// 해당 숫자가 고장나지 않았다면
	if(!broken[number1]) {
		rn[1]=number1*10;
		if(!broken[number2]) {
			rn[1]+=number2;
		} else {
			for(int i=1;i<10;i++) {
				if(0<=number2-i && !broken[number2-i]) {
					rn[1]+=number2-i;
					break;
				}
				if(number2+i<=9 && !broken[number2+i]) {
					rn[1]+=number2-i;
					break;
				}
			}
		}
	}
	
	// 해당 주위 숫자를 탐색한다.
	for(int i=1;i<10;i++) {
		if(0<=number1-i && !broken[number1-i]) {
			rn[0]=(number1-i)*10;
			
			for(int j=9;0<=j;j--) {
				if(!broken[j]) {
					rn[0]+=j;
					break;
				}
			}
		}
		
		if(number1+i<=9 && !broken[number1+i]) {
			rn[2]=(number1+i)*10;
			
			for(int j=0;j<=9;j++) {
				if(!broken[j]) {
					rn[2]+=j;
					break;
				}
			}
		}
		
		if(rn[0]!=-1 || rn[2]!=-1) break;
	}
	
	int on = stoi(sn.substr(digit-d,2));
	
	for(int i=0;i<3;i++) {
		cn[i] = on-rn[0];
	}
	
	rn[0] > rn[2]
	rn[1] > rn[0,2]
	
	
	// 수정 필요
	result += pow(10,d-1);
}

int main(void) {
	cin>>n>>m;
	
	// 자릿수 세기
	for(int i=1;i<=100000;i*=10) {
		if(0 < n/i) digit++;
	}
	
	int input;
	for(int i=0;i<m;i++) {
		cin>>input;
		broken[input]=1;
	}
	
	cout<<solve(digit)<<endl;
}
*/