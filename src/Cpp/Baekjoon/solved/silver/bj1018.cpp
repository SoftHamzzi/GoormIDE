#include <iostream>

using namespace std;

int repaint(char (*chess)[50], int is, int js) {
	int cnt=0;
	for(int i=is;i<is+8;i++) {
		for(int j=js;j<js+8;j++) {
			if((i+j)%2==1 && chess[i][j]=='B')
				cnt++;
			else if((i+j)%2==0 && chess[i][j]=='W')
				cnt++;
		}
	}
	
	int min = cnt>64-cnt ? 64-cnt:cnt; 
	return min;
}

int main(void) {
	int m,n;
	int min=64;
	cin>>m>>n;
	
	char chess[50][50];
	
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>chess[i][j];
		}
	}
	
	for(int i=0;i<m-7;i++) {
		for(int j=0;j<n-7;j++) {
			int rp = repaint(chess,i,j);
			// rp가 0인 경우 출력 후 바로 프로그램 종료
			if(!rp) {
				cout<<"0\n";
				return 0;
			}
			// rp가 현재 min보다 작은 경우 min을 교체
			if(rp < min) {
				min = rp;
			}
		}
	}
	cout<<min<<"\n";
	return 0;
}