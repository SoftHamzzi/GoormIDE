#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to) {
	if(num==1) {
		printf("num==1, %c -> %c\n", from, to);
	} else {
		HanoiTowerMove(num-1,from,to,by);
		printf("%c -> %c\n", from, to);
		HanoiTowerMove(num-1,by,from,to);
	}
}

int main(void) {
	HanoiTowerMove(3, 'A', 'B', 'C');
}