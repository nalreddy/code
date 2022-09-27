#include<stdio.h>
#include"slist.h"


int main(void) {
	int i;
	List* list = makeList();

	for( i = 1; i < 5; i++) {
		addLast(i,list);
	}

	display(list);
//	reverse(list);
	listMid(list);
	display(list);
	//delList(list);

	return 0;
}
