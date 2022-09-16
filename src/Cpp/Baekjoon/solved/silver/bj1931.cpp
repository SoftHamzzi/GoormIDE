#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool comp(pair<int,int> p1, pair<int,int> p2) {
	if(p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin>>n;
	int max=0;
	
	int s,e;
	for(int i=0; i<n; i++) {
		
		cin>>s>>e;
		v.push_back(make_pair(s,e));
		
	}
	
	sort(v.begin(), v.end(), comp);
	
	int cur = v[0].second;
	int cnt=1;
	for(int i=1; i<n; i++) {
		
		if(cur <= v[i].first) {
			cur = v[i].second;
			cnt++;
		}
	}
	
	cout << cnt << endl;
		
}