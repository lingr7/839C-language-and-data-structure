/*带表头结点的环形双向链表*/
/*在带表头结点的环形链表中 
insert:将值为y的结点插在值为x的结点后面
delete:删除值为x的结点*/
#include <stdio.h>
struct node{
	char data;
	struct node *llink, *rlink;
}; 
typedef struct node NODE;
NODE *head;
int insert_d_l(NODE *head, char x, char y){
	NODE *p, *q;
	p = head->rlink;
	while(p != head && p->data !=x)
		p = p->rlink;
	if (p == head)
		return 1;
	q = (NODE*)malloc(sizeof(NODE));
	q->data = y;
	q->rlink = p->rlink;
	p->rlink = q;
	q->rlink->llink = q;
	q->llink = p;
	return 0; 
}
int delete_d_l(NODE *head, char x){
	NODE *p;
	p = head->rlink;
	while(p != head && p->data != x)
		p = p->rlink;
	if(p == head)
		return 1;
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	free(p);
	return 0;
}
