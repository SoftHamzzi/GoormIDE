#include <iostream>

using namespace std;

// 접점의 갯수를 구하는 함수
int numberOfContact(int* p1, int* p2) {
	int d = (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
	int cond1 = (p1[2]-p2[2])*(p1[2]-p2[2]);
	int cond2 = (p1[2]+p2[2])*(p1[2]+p2[2]);
	if(d==0) {
		if(cond1 == 0) {
			return -1;
		} else {
			return 0;
		}
	} else if(cond1 < d && d < cond2) {
		return 2;
	} else if(cond1 == d || cond2 == d) {
		return 1;
	} else {
		return 0;
	}
	return -100;
}

int main(void) {
	int n; cin>>n;
	int p1[3], p2[3];
	
	for(int i=0;i<n;i++) {
		cin>>p1[0]>>p1[1]>>p1[2];
		cin>>p2[0]>>p2[1]>>p2[2];
		
		cout<< numberOfContact(p1,p2) <<endl;
	}
	return 0;
}