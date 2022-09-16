//#include <iostream>
//#include <map>
//#include <queue>
//
//using namespace std;
//
//map<int, int> connect;
//int roll[101];
//
//int LadderAndSnake() {
//	
//	queue<int> q;
//	
//	q.push(1);
// 
//	while(!q.empty()) { // 큐가 빌 때까지
//	
//		int origin = q.front();
//		q.pop(); // 큐 하나 삭제
//		
//		for(int i=origin+1; i<=origin+6; i++) {
//			
//			if(i>100) {
//				continue;
//			}
//			
//			if(connect.find(i) != connect.end() && roll[connect[i]]==-1) { // 뭔가 있으며, 이어진 곳이 간적 없는 곳이라면 
//				roll[connect[i]] = roll[origin] + 1;
//				q.push(connect[i]);
//			} else if(connect.find(i) == connect.end() && roll[i]==-1) {
//				roll[i] = roll[origin] + 1;
//				q.push(i);
//			}
//			
//		}
//		
//	}
//	
//	return roll[100];
//	
//}
//
//int main(void) {
//	
//	int ladder, snake; cin>>ladder>>snake;
//	
//	int s,e;
//	for(int i=0; i<ladder+snake; i++) {
//		cin>>s>>e;
//		
//		connect[s] = e;
//	}
//	
//	for(int i=0; i<101; i++) {
//		roll[i] = -1;
//	}
//	roll[1]=0;
//	
//	cout << LadderAndSnake() << endl;
//	
//}

#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, int> connect;
int roll[101];

int LadderAndSnake() {
	
	queue<int> q;
	
	q.push(1);
	
	int maxPos; 
	while(!q.empty()) { // 큐가 빌 때까지
	
		maxPos=0;
		for(int i=q.front()+1; i<=q.front()+6; i++) {
			
			if(i>100) {
				continue;
			}
			
			if(connect.find(i) != connect.end() && (roll[q.front()]+1 < roll[connect[i]] || roll[connect[i]]==0)) {
			// 6 주사위 안에 사다리가 있으며, 사다리를 건넌 곳의 굴린 횟수보다 적거나 0인 경우 
				
				q.push(connect[i]);
				roll[connect[i]] = roll[q.front()]+1;
				
			} else if(connect.find(i) == connect.end() && (roll[q.front()]+1 < roll[i] || roll[i]==0)){
				
				maxPos = i;
				
			}
		}
		
		if(maxPos!=0 && maxPos<=100) {
			if(maxPos != 100)
				q.push(maxPos);
			if(roll[q.front()]+1 < roll[maxPos] || roll[maxPos]==0)
				roll[maxPos] = roll[q.front()]+1;
		}
		
		q.pop(); // 큐 하나 삭제
		
	}
	
	return roll[100];
	
}

int main(void) {
	
	int ladder, snake; cin>>ladder>>snake;
	
	int s,e;
	for(int i=0; i<ladder+snake; i++) {
		cin>>s>>e;
		
		connect[s] = e;
	}
	
	cout << LadderAndSnake() << endl;
	
//	for(int i=1; i<=100; i++) {
//		if(i%10==1)
//			cout<<endl;
//		cout << roll[i] << "\t";
//	}
//	cout<<endl;
	
}