#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin>>t;
	string s1;
	string s2;
	
	int p1;
	int p2;
	int size;
	int cnt;
	for(int i=0;i<t;i++) {
		cin>>s1;
		cin>>s2;
		p1=0;
		p2=0;
		cnt=0;
		
		while(1) {
			if(p2>=s2.size()) { // p2가 s2를 다 돈 경우
				if((s1.size()-p1)%2 == 0) { // 뒤에 남은 문자열의 갯수가 짝수
					cout<<"YES\n";
					break;
				} else { // 뒤에 남은 문자열의 갯수가 홀수 (s1=abacba, s2=ba 같은 상황을 위해)
					p2=0;
					cnt=0;
				}
			} else if(p1>=s1.size()) { // p1이 s1을 다 돈 경우
				cout<<"NO\n";
				break;
			}
			
			// 비교한 문자열이 같은 경우
			if(s2[p2] == s1[p1] && cnt%2==0) {
				p1++;
				p2++;
				cnt=0;
			} else { // 비교한 문자열이 다른 경우
				if(p2==0) { // 아직 같은 문자를 하나도 못찾았다면
					p1++;
				} else { // 같은 문자를 하나라도 찾은 경우
					p1++;
					cnt++;
				}
			}
			cout<<p1+1<<" "<<p2+1<<"\n";
		}
	}
}