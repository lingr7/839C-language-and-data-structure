#include <stdio.h>  
#include <stdlib.h>  
#include<malloc.h>
typedef struct Node  
{  
    int data;  
    struct Node *pNext;  
    struct Node *pPre;  
}NODE, *pNODE;  
 
//创建双向循环链表  
pNODE Create(void)  
{  
    int i, length = 0, data = 0;  
    pNODE p_new = NULL, pTail = NULL;  
    pNODE pHead = (pNODE)malloc(sizeof(NODE));  
  
    if (NULL == pHead)  
    {  
        printf("内存分配失败！\n");  
        exit(1);  
    }  
    pHead->data = 0;  
    pHead->pNext = pHead;  
    pHead->pPre = pHead;  
    pTail = pHead;  
  
    printf("请输入想要创建链表的长度：");  
    scanf("%d", &length);  
  
    for (i=1; i<length+1; i++)  
    {  
        p_new = (pNODE)malloc(sizeof(NODE));  
  
        if (NULL == p_new)  
        {  
            printf("内存分配失败！\n");  
            exit(1);  
        }  
  
        printf("请输入第%d个节点元素值：", i);  
        scanf("%d", &data);  
  
        p_new->data = data;  
        p_new->pPre = pTail;  
        p_new->pNext = pHead;  
        pTail->pNext = p_new;  
        pHead->pPre = p_new;  
        pTail = p_new;  
    }  
    return pHead;  
} 
void TraverList(pNODE pHead)  
{  
    pNODE pt = pHead->pNext;  
  
    printf("链表打印如：");  
    while (pt != pHead)  
    {  
        printf("%d ", pt->data);  
        pt = pt->pNext;  
    }  
    putchar('\n');  
}  
int  Judge(pNODE L){
	Node *p=L->pNext,*q=L->pPre;
	while(p!=q&&p->pNext!=q){
		if(p->data!=q->data) return 0;
		p=p->pNext;q=q->pPre;
	}
	return 1;
}
int main(){
	Node *p;int n;
	p=Create();
	n=Judge(p);
	if(n)  printf("\n是");
	else printf("\n不是");
	return 0;
}
