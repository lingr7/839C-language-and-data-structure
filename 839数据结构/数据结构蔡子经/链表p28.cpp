/*
	Name: 链表 
	Copyright: 
	Author: lingr7 
	Date: 04/11/18 17:17
	Description: 
*/
#include <stdio.h>
typedef struct node{
	char data;
	struct node *link;//自引用结构,link是指向该类型的指针 
} NODE;//NODE就是新类型的名字，同时该类型是一个结构。《C程序设计语言》K&R版本第6章结构6.7内容 
NODE *head, *p, *q;//head,p,q都是指向该类型的指针 
head = (NODE * )malloc(sizeof(NODE)); 
NODE *create_link_list(int n){
	int i;
	NODE *head, *p, *q;
	if(n==0)
		return NULL;
	head = (NODE*)malloc(sizeof(NODE));
	p = head;
	for(i = 1; i < n; i++){
		scanf("%c",&(p-data));
		q = (NODE*)malloc(sizeof(NODE));
		p->link = q;
		p = q; 
	}
	scanf("%c", &(p->data));
	getchar();
	p->link=NULL;
	return head;
}

