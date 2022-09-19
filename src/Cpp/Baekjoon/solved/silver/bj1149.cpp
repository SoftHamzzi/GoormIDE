#include <iostream>
#include <algorithm>

using namespace std;

int n;
int rgb[1001][3];
int table[1001][3];

int solve() {
	
	for(int i=1; i<n; i++) {
		
		table[i][0] = min(table[i-1][1] + rgb[i][0], table[i-1][2] + rgb[i][0]);
		table[i][1] = min(table[i-1][0] + rgb[i][1], table[i-1][2] + rgb[i][1]);
		table[i][2] = min(table[i-1][0] + rgb[i][2], table[i-1][1] + rgb[i][2]);
		
	}
	
	return min(table[n-1][0], min(table[n-1][1], table[n-1][2]));
	
}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	int r,g,b;
	for(int i=0; i<n; i++) { // 입력 받기 
		cin>>r>>g>>b;
		rgb[i][0] = r;
		rgb[i][1] = g;
		rgb[i][2] = b;
	}
	
	table[0][0] = rgb[0][0];
	table[0][1] = rgb[0][1];
	table[0][2] = rgb[0][2];
	
	cout << solve() << endl;
	
}