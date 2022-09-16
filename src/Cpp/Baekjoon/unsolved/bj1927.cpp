#include <iostream>

using namespace std;

unsigned long long queue[200001];
int _size=0;

int min(unsigned long long a, unsigned long long b) { // 두 숫자 중 작은 값을 찾는 함수. 왼쪽이 작으면 -1, 같다면 0, 오른쪽이 작다면 1
	if(a==b) return 0;
	return a<b ? -1:1;
}

void swap(int& a, int& b) { // 두 위치의 값을 바꾸는 함수
	
	unsigned long long temp = a;
	a = b;
	b = temp;
	
}

void queue_push(unsigned long long x) { // 큐에 삽입하는 함수
	
	_size++;
	int cur = _size;
	
	queue[cur] = x;
	
	while(queue[cur/2] > queue[cur] && cur != 1) {
		
		swap(queue[cur/2], queue[cur]);
		cur /= 2;
		
	}
	
}

unsigned long long queue_pop() { // 큐에서 꺼내는 함수
	
	if(_size == 0)
		return 0;
	
	int cur = 1;
	unsigned long long value = queue[1];
	
	swap(queue[1], queue[_size]);
	_size--;

	while(cur <= _size) {
		
		if(cur*2+1 <= _size) { // 리프 노드가 2개인 경우
			// cout << queue[cur*2] << " " << queue[cur*2+1] << endl;
			if(min(queue[cur*2], queue[cur*2+1]) == -1) {
				
				if(min(queue[cur], queue[cur*2]) == 1) {
					swap(queue[cur], queue[cur*2]);
					cur = cur*2;
				} else {
					break;
				}
				
			} else if(min(queue[cur*2], queue[cur*2+1]) == 1) {
				
				if(min(queue[cur], queue[cur*2+1]) == 1) {
					swap(queue[cur], queue[cur*2+1]);
					cur = cur*2+1;
				} else {
					break;
				}
				
			} else {
				break;
			}
			
		} else if(cur*2 == _size) { // 리프 노드가 1개인 경우
			
			if(min(queue[cur], queue[cur*2]) == 1) {
				
				swap(queue[cur], queue[cur*2]);
				cur = cur*2;
				break;
				
			} else {
				break;
			}
			
		} else { // 리프 노드가 하나도 존재하지 않는 경우
			break;
		}
		
	}
	
	return value;

}

int main(void) {
	
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n; cin>>n;
	
	unsigned long long temp;
	while(n--) {
		
		cin>>temp;
		if(temp==0) {
			cout << queue_pop() << endl;

		} else {
			queue_push(temp);
			
		}
	}
}