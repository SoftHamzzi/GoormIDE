#include <stdio.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void) {
	List list;
	ListInit(&list);
	NameCard * pcard;
	
	// 1. 총 3명의 전화번호 정보를, 리스트에 저장한다.
	pcard = MakeNameCard("이영진", "010-1111-3333");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("임동규", "010-5555-9999");
	LInsert(&list, pcard);
	
	pcard = MakeNameCard("박건우", "010-9999-7777");
	LInsert(&list, pcard);
	
	// 2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard,"임동규")) {
			ShowNameCardInfo(pcard);
		}
		else {
			while(LNext(&list, &pcard)) {
				if(!NameCompare(pcard,"임동규")) {
					ShowNameCardInfo(pcard);
				}
			}
		}
	}
	
	// 3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다.
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard,"이영진")) {
			ChangePhoneNum(pcard, "010-9259-9664");
		}
		else {
			while(LNext(&list, &pcard)) {
				if(!NameCompare(pcard,"이영진")) {
					ChangePhoneNum(pcard, "010-9259-9664");
				}
			}
		}
	}
	
	// 4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.
	if(LFirst(&list, &pcard)) {
		if(!NameCompare(pcard,"박건우")) {
			LRemove(&list);
		}
		else {
			while(LNext(&list, &pcard)) {
				if(!NameCompare(pcard,"박건우")) {
					LRemove(&list);
				}
			}
		}
	}
	
	// 5. 끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.
	if(LFirst(&list, &pcard)) {
		ShowNameCardInfo(pcard);
		while(LNext(&list, &pcard)) {
			ShowNameCardInfo(pcard);
		}
	}
	
	return 0;
}