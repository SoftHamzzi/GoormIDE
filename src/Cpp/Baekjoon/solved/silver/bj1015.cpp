#include <iostream>

using namespace std;

int main(void) {
	int n; cin>>n;
	int a[50];
	int r[50];
	
	// 입력
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	// 비내림차순 정렬
	int* min = NULL;
	int p;
	for(int i=0;i<n;i++) {
		int p = 0;
		min = NULL;
		for(int j=0;j<n;j++) {
			// min이 NULL이며 a[j]가 -1이 아닐때
			if(min==NULL && a[j]!=-1) {
				min = &a[j];
				p=j;
			}
			// min값이 있으며 *min이 a[j]보다 클떄
			else if(min!=NULL && *min > a[j] && a[j]!=-1) {
				min = &a[j];
				p=j;
			}
		}
		r[p] = i;
		*min = -1;
	}
	
	// 출력
	for(int i=0;i<n;i++) {
		cout<<r[i]<<" ";
	}
}