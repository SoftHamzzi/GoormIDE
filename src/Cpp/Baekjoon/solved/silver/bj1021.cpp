// 회전하는 큐
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int findNumber(deque<int>& dq, int pNum) {
	int cnt=0;
	int size = dq.size();
	
	while(dq.front() != pNum) {
		// 앞에 있는 원소를 뒤로 넘깁니다.
		dq.push_back(dq.front());
		dq.pop_front();
		
		cnt++;
	}
	
	int r; 
	return r = size-cnt > cnt ? cnt : size-cnt; 
}

void removeNumber(deque<int>& dq) {
	dq.pop_front();
}

int main(void) {
	// n은 숫자의 갯수, m은 뽑아야 할 숫자의 갯수
	int n,m; cin>>n>>m;
	int sum=0;
	deque<int> dq;
	queue<int> pick;
	
	// 뽑아야 할 숫자 입력
	int input;
	for(int i=0;i<m;i++) {
		cin>>input;
		pick.push(input);
	}
	
	// deque에 숫자 넣기
	for(int i=1;i<=n;i++) {
		dq.push_back(i);
	}
	
	// 숫자 뽑기 시작
	int pNum;
	for(int i=0;i<m;i++) {
		pNum = pick.front();
		pick.pop();
		
		sum += findNumber(dq,pNum);
		removeNumber(dq);
	}
	
	// 최종 sum값 출력
	cout<<sum<<endl;
}