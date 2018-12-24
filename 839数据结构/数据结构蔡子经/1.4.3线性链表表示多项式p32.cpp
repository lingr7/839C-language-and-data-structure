/*1.4.2用线性链表表示多项式*/
/*
	Name: 多项式加法 
	Copyright: 
	Author: lingr7
	Date: 11/11/18 13:15
	Description: 附加结点空间的处理代码要小心在意，
	switch可以对字符操作也是活久见 
*/

/*表示两个多项式相加。
其中第一个函数产生一个新的结点，
其系数为c，指数为e,
并把新结点挂在pc所指的结点之后，
然后返回新结点的地址，
第二个函数实现由线性链表ah,bh表示的两个多项式相加，
为了处理上的方便，
在进行相加之前，
首先产生一个附加结点，
在得到结果多项式的线性链表之后，
再删除这个附加结点。*/
include <stdio.h>
struct node{
	int coef;/*存放系数*/
	int exp;/*存放次数*/
	struct node *link;/*自引用结构，存放下一项地址*/ 
};
typedef struct node NODE;
NODE *ah, *bh, *ch;
NODE *insert(NODE *pc, int c, int e){
	NODE *t;
	t = (NODE*)malloc(sizeof(NODE));
	t->coef = c;
	pc->link = t;
	return t;
}
NODE *polyadd_1(NODE *ah, NODE *bh){
	NODE *pa, *pb, *ch, *pc;
	char c;
	ch = (NODE*)malloc(sizeof(NODE));
	pc = ch;
	pa = ah;
	pb = bh;
	/*将两个多项式中，次数相同的系数取和，
	次数不同时，取次数较高的那个的系数，
	被取过的结点就过，不再重复取，到下一结点*/
	while(pa !=NULL && pb != NULL){
		if (pa->exp == pb->exp)
			c = '=';
		else if(pa->exp > pb->exp)
			c = '>';
		else 
			c = '<';
		switch(c);
		{
			case '=':
				if(pa->coef + pb->coef != 0){
					pc = insert(pc, pa->coef + pb->coef, pa->exp);
				}
				pa = pa->link;
				pb = pb->link;
				break;
			case '>':
				pc = insert(pc, pa->coef, pa->exp);
				pa = pa->link;
				break;
			case '<':
				pc = insert(pc, pb->coef, pb->exp);
				pb = pb->link;
				break; 		
		}
	}
	/*遇到ah或bh某一个已经取完的，没取完的那个继续*/
	while (pa != NULL){
		pc = insert(pc, pa->coef, pa->exp);
		pa = pa->link;
	}
	while (pb != NULL){
		pc = insert(pc, pb->coef,pb->exp);
		pb = pb->link;
	}
	pc->link = NULL;/*构造多项式链表空间完毕*/
	pc = ch;
	ch = ch->link;/*这里还有return 语句是在多项式链表中去除第一个附加结点（附加结点coef还有exp为空）*/
	free(pc);/*现在可以释放掉当初那个附加结点占用的空间了*/
	return ch;
}
int main(){
	
	
	
	
	
	
	
	return 0;
} 
