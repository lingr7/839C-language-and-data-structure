#include<stdio.h>
#include<malloc.h>
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct{
	BiTree data[100];
	int front,rear;
	int level[10];
}Qu; 
BiTree Create(int A[],int B[],int l1,int h1,int l2,
int h2)  
{    
	int llen,rlen,i;
	BiTNode *r=(BiTNode*)malloc(sizeof(BiTNode));
	r->data=B[h2]; 
	for(i=l1;A[i]!=r->data;i++);
	llen=i-l1;rlen=h1-i;
	if(llen) r->lchild=Create(A,B,l1,l1+llen-1,l2,l2+
	llen-1);
	else r->lchild=NULL;
	if(rlen) r->rchild=Create(A,B,h1-rlen+1,h1,
	h2-rlen,h2-1);
	else r->rchild=NULL;
	return r;      
} 
int  Width(BiTree b){
	Qu  Q;
	int i,k,max,n;
	BiTree p;
	Q.front=-1;
	Q.rear=0;
	Q.level[Q.rear]=1;
	Q.data[Q.rear]=b;
	while(Q.front<Q.rear){
		Q.front++;
		k=Q.level[Q.front];
		p=Q.data[Q.front];
		if(p->lchild!=NULL){
			Q.rear++;
			Q.data[Q.rear]=p->lchild;
			Q.level[Q.rear]=k+1;
		}
		if(p->rchild!=NULL){
			Q.rear++;
			Q.data[Q.rear]=p->rchild;
			Q.level[Q.rear]=k+1;
		}
		
	}
		max=0;i=0;
		k=1;
		while(i<=Q.rear){
			n=0;
			while(i<=Q.rear&&Q.level[i]==k){
				i++;
				n++;				
			}
			if(max<n)	max=n;	
			k++;	
		}
	return max;	
} 
int main(){
	BiTNode *t;
	int A[15]={8,4,9,2,5,1,6,3,7};
	int B[15]={8,9,4,5,2,6,7,3,1};
	int l1=0,h1=8,l2=0,h2=8;
	t=Create(A,B,l1,h1,l2,h2);
	printf("%d",Width(t)); 
	return 0;
}
 
 

 
