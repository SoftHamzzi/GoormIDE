#include <iostream>

using namespace std;

int main(void) {
	int n; cin>>n;
	int x,y;
	
	int p[50][3];
	for(int i=0;i<n;i++) {
		cin>>x; cin>>y;
		p[i][0]=x;
		p[i][1]=y;
		p[i][2]=0;
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i==j) continue; 
			if(p[i][0] < p[j][0] && p[i][1] < p[j][1])
				p[i][2]++;
		}
		cout<<p[i][2]+1<<" ";
	}
}