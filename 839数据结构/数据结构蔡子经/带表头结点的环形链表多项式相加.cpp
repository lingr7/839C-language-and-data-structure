/*带表头结点的环形链表表示的多项式相加的程序*/
/*
	Name: 
	Copyright: 
	Author: lingr7
	Date: 11/11/18 15:43
	Description: 
*/

#include <stdio.h>
struct node{
	int coef;
	int exp;
	struct node *link;
};
typedef struct node NODE;
NODE *ah, *bh, *ch;

NODE *insert(NODE *pc, int c, int e){
	NODE *t;
	t = (NODE*)malloc(sizeof(NODE));
	t->coef = c;
	t->exp = e;
	pc->link = t;
	return t;
}
NODE *polyadd_(NODE *ah, NODE *bh){
	NODE *pa, *pb, *ch, *pc;
	char c;
	ch = (NODE*)malloc(sizeof(NODE));
	ch->exp = -1;
	pc = ch;
	pa = ah->link;
	pb = bh->link;
	while(pa->exp !=-1 || pb->exp!= -1){
		if(pa->exp == pb->exp)
			c = '=';
		else if(pa->exp > pb->exp)
			c = '>';
		else c = '<';
		switch(c){
			case '=':
				if(pa->coef + pb->coef != 0){
					pc = insert(pc,
								pa->coef + pb->coef,
								pa->exp);
				}
				pa = pa->link;
				pb = pb->link;
				break;
			case '>':
				pc = insert(pc, pa->coef,
							pa->exp);
				pa = pa->link;
				break;
			case '<':
				pc = insert(pc, pb->coef,
							pb->exp);
				pb = pb->link;
				break;
		}
	}	
	pc->link = ch;/*pc已经是有coef与exp的最后一个结点，使其与表头结点接在一起*/
	return ch; 
}
