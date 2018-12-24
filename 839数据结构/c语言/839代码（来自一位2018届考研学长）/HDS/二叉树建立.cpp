#include<stdio.h>
#include<malloc.h> 
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct eNode{
	int data;
	struct eNode *lchild,*rchild;
	struct eNode *parent;
}eNode,*eTree;
BiTree Create()  
{     
    BiTNode *p;  
    int ch;  
    scanf("%d",&ch);
    if(ch == 0)     
    {  
        p = NULL;  
    }  
    else  
    {  
        p = (BiTNode*)malloc(sizeof(BiTNode));  
        p->data = ch;  
        p->lchild = Create();   
        p->rchild = Create();   
    }  
    return p;  
} 
void Extend(BiTree b,eTree t){
	t->data=b->data;
	if(b->lchild!=NULL){
		eNode *p=(eNode *)malloc(sizeof(eNode));
		p->parent=t;
		t->lchild=p;
		Extend(b->lchild,t->lchild);
	}
	else t->lchild=NULL;
	if(b->rchild!=NULL){
		eNode *p=(eNode *)malloc(sizeof(eNode));
		p->parent=t;
		t->rchild=p;
		Extend(b->rchild,t->rchild);
	}
	else t->rchild=NULL;
}   
 
int main(){
	BiTNode *t;
	eNode *r=(eNode *)malloc(sizeof(eNode)); 
	r->parent=NULL;
	t=Create();
 	Extend(t,r);
 	printf("%d",r->rchild->rchild->lchild->parent->data);
 	return 0;
}
 
 

 
