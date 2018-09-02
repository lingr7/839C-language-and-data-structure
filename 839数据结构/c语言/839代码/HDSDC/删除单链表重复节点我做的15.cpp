#include<stdio.h>
#include<malloc.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
 
struct LNode *creat(int n){
	int i;
	struct LNode *head,*p1,*p2;
	int a;
	head=NULL;
	for(i=1;i<=n;i++){
	p1=(struct LNode *)malloc(sizeof(struct LNode));
	printf("请输入链表中的第%d个数：",i);
	scanf("%d",&a);
	p1->data=a;
	if(head==NULL) {
	head=p1;
	p2=p1;
	}
	else{
	p2->next=p1;
	p2=p1;
	}
	p2->next=NULL; 
	}
	return head; 
}
void Del(LNode *head){
	LNode *p=head,*q,*s;
	int f;
	if(p==NULL||p->next==NULL) return;
	while(p->next!=NULL){
	  	for(q=p;q->next!=NULL;)
	  		if(q->next->data==p->data){
	  			LNode *r=q->next;
	  			q->next=r->next;
	  			free(r);
			  }
			else q=q->next;
		p=p->next;	
	}
}
int  main()
{
	int n;
	struct LNode *q;
	printf("请输入链表的长度：\n");
	scanf("%d",&n);
	q=creat(n); 
	printf("\n链表中的数据：\n");
	Del(q);
	while(q) {
	printf("%d ",q->data); 
	q=q->next; 
	}
	return 0;
}

