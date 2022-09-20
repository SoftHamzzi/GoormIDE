#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> crain;
vector<int> box;

bool comp(int a, int b) {
	return a>b;
}

int solve() {
	
	int cnt=0;
	
	if(crain[0] < box[0])
		return -1;
	
	while(!box.empty()) {
		for(int c : crain) {
			for(auto b = box.begin(); b!= box.end(); b++) {
				if(c>=*b) {
					cout << c << " erase " << *b << " at cnt " << cnt << endl;
					box.erase(b);
					break;
				}
			}
		}
		cnt++;
	}
	
	return cnt;
	
}

int main(void) {
	
	int cn;
	int bn;
	int temp;
	
	cin>>cn;
	for(int i=0; i<cn; i++) {
		
		cin>>temp;
		crain.push_back(temp);
		
	}
	
	cin>>bn;
	for(int i=0; i<bn; i++) {
		
		cin>>temp;
		box.push_back(temp);
		
	}
	
	sort(crain.begin(), crain.end(), comp);
	sort(box.begin(), box.end(), comp);
	
	cout << solve() << endl;
	
}