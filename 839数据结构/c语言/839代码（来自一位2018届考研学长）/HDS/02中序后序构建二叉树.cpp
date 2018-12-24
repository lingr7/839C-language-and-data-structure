#include<stdio.h>
#include<malloc.h> 
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void Pre(BiTNode *b){
	if(b!=NULL){
		printf("%2d",b->data);
		Pre(b->lchild);
		Pre(b->rchild);
	}
}
BiTree Create(int A[],int B[],int l1,int h1,int l2,int h2){
	BiTNode *b=(BiTNode *)malloc(sizeof(BiTNode));
	b->data=B[h2];
 	int i;
	for(i=l1;A[i]!=b->data;i++)  ;
	int llen=i-l1;
	int rlen=h1-i;
	if(llen)  b->lchild=Create(A,B,l1,l1+llen-1,l2,l2+llen-1);
	else  b->lchild=NULL;
	if(rlen)  b->rchild=Create(A,B,h1-rlen+1,h1,h2-rlen,h2-1);
	else b->rchild=NULL;
	return b;
}
int main(){
	int A[7]={8,2,1,6,5,7,4};
	int B[7]={8,2,6,1,7,4,5};
	BiTNode *p=Create(A,B,0,6,0,6);
	Pre(p);
	return 0;
}
