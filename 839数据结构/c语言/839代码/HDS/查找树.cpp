#include<stdio.h>
#include<malloc.h>
int t;
typedef struct Node  
{  
    int  data;  
    struct Node *lchild;  
    struct Node *rchild;  
}Node;  
int  findIN(Node *root,int d,int k){
	t=-1;
	if(root->data==k) return d;
	if(root->data>k&&root->lchild!=NULL)  t=findIN(root->lchild,d+1,k);
	if(root->data<k&&root->rchild!=NULL)  t=findIN(root->rchild,d+1,k);
	return t;
	
}
Node* createBinaryTree()  
{     
    Node *p;  
    int ch;  
    scanf("%d",&ch);
    if(ch == 0)     
    {  
        p = NULL;  
    }  
    else  
    {  
        p = (Node*)malloc(sizeof(Node));  
        p->data = ch;  
        p->lchild = createBinaryTree();   
        p->rchild = createBinaryTree();   
    }  
    return p;  
}  
int main()  
{  
	int k;int c; 
    Node *root = NULL;  
    root = createBinaryTree();
    printf("Please input a num:\n");
    scanf("%d",&k);
	c=findIN(root,0,k);  
	printf("²ãÊýÎª:%d\n",c);
    return 0;  
}  
