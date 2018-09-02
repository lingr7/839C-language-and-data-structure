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
int main(){
	BiTNode *t;
	int v,l=0;
	printf("Please input point:\n");
	t=Create();
	return 0;
}
 
 

 
