#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "CLinkedList.h"

Employee * WhoIsNightDuty(List * plist, char * name, int day) {
	Employee *ret;
	
	int i;
	int num = LCount(plist);
	
	LFirst(plist, &ret);
	
	if(strcmp(ret->name,name)!=0) {
		for(i=0;i<num-1;i++) {
			LNext(plist, &ret);
			
			if(strcmp(ret->name, name) == 0) {
				break;
			}
			if(i>= num-2) {
				printf("실행\n");
				return NULL;
			}
		}
	}
	
	for(i=0;i<day;i++)
		LNext(plist, &ret);
	
	return ret;
}

void ShowEmployeeInfo(Employee * emp) {
	printf("empNum: %d, name: %s\n", emp->empNum, emp->name);
}

int main(void) {
	List list;
	ListInit(&list);
	
	Employee * pemp;
	
	// malloc 또 해야하나?
	//pemp=(Employee*)malloc(sizeof(Employee));
	pemp->empNum=33330000;
	strcpy(pemp->name,"삼양");
	LInsert(&list, pemp);
	
	//pemp=(Employee*)malloc(sizeof(Employee));
	pemp->empNum=11110000;
	strcpy(pemp->name,"일영");
	LInsert(&list, pemp);
	
	//pemp=(Employee*)malloc(sizeof(Employee));
	pemp->empNum=55559999;
	strcpy(pemp->name,"오구");
	LInsert(&list, pemp);
	
	//pemp=(Employee*)malloc(sizeof(Employee));
	pemp->empNum=99999999;
	strcpy(pemp->name,"구구");
	LInsert(&list, pemp);
	
	pemp = WhoIsNightDuty(&list, "오구", 8);
	ShowEmployeeInfo(pemp);
	
	return 0;
}