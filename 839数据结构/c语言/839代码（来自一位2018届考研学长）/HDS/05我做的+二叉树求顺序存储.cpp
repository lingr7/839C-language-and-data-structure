typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void Creat(BiTree b,int A[]){
	Queue Q;
	InitQueue(Q);
	BiTree p;
	int k=-1;
	Enqueue(Q,b);
	A[0]=b->data;
	while(!IsEmpty(Q)){
		Pop(Q,p);
		k++;
		if(p->lchild!=NULL){
			Push(Q,p->lchild);
			A[2*k+1]=p->lchild->data;
		}
		else A[2*k+1]=-1;
		if(p->rchild!=NULL){
			Push(Q,p->rchild);
			A[2*k+2]=p->rchild->data;
		}
		else A[2*k+2]=-1;
} 
