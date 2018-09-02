#include<stdio.h>
#include<malloc.h>
typedef struct LNode
{
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
		if(head==NULL){ 
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
void print(LNode *h)
{
	LNode *i=h->next;
	while(i){
	printf("%d ",i->data); 
	i=i->next;
	}
}
void Devided(LinkList &h,LinkList &h1,LinkList &h2){
	LNode *p=(struct LNode *)malloc(sizeof(struct LNode));
	LNode *q=(struct LNode *)malloc(sizeof(struct LNode));
	h1=p;
	h2=q;
	int i=0;
	while(h){
		i++;
		if(h->data<i){
		p->next=h;
		p=h;	
		}
		else{
		q->next=h;
		q=h;	
		}
		h=h->next;
	}
	p->next=NULL;
	q->next=NULL;
	
}
int  main()
{
int n;
struct LNode *q,*h1,*h2;
printf("请输入链表的长度：\n");
scanf("%d",&n);
q=creat(n); 
printf("\n链表中的数据：\n");
Devided(q,h1,h2);h1=h1->next;
	h2=h2->next;
	while(h1){
	printf("%d ",h1->data); 
	h1=h1->next;
	}
	printf("\n");
	while(h2){
	printf("%d ",h2->data); 
	h2=h2->next;
	}
return 0;
}
