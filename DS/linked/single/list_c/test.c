#include<stdio.h>
#include"slist.h"


int main(void) {
	int i;
	List* list = makeList();

	//for( i = 1; i < 5; i++) {
	//	addLast(i,list);
	//}

	addLast(0,list);
	addLast(1,list);
//	display(list);
//	reverse(list);
//	listMid(list);
	display(list);
	makeLoop(list);
	detectLoop(list);
	//delList(list);

	return 0;
}
