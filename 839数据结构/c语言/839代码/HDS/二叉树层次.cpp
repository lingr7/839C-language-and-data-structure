#include<stdio.h>
#include<malloc.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
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
int result;
int level(BiTree t,int k,int l){
    result=-1;
	if(t!=NULL){
		if(t->data==k) return l;
		if(t->lchild!=NULL&&t->data>k) 
			result=level(t->lchild,k,l+1);
		if(result>=0) 
			return result;
		if(t->rchild!=NULL&&t->data<k)
			 result=level(t->rchild,k,l+1);
		if(result>=0) 
			return result;
	}
}
int main(){
	BiTNode *t;int v,l=0;
	printf("Please input point:\n");
	t=Create();
	int n;scanf("%d",&n);
	printf("\nLevel :%d",level(t,n,0)); 
	return 0;
}
 
 

 
