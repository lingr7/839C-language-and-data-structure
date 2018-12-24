/*
	Name: 
	Copyright: 
	Author: 
	Date: 16/12/18 22:19
	Description: 此时还有4道题目 
*/
/*四、定义一个函数删除一个单向链表的重复节点，不使用临时缓冲区
函数原型为 void Remove Duplicates(LINK *head); 自定义节点类型LINK,节点存放的是一个整型数据.*/

    
typedef struct LNode LINK;
struct LNode
{
    int data;
    LINK* Next;
};
void Remove Duplicates(LINK *head)
{
    LINK *curr,*prev,*tmp;
    curr=head;
    while(curr)
    {
        tmp=curr->Next;
        prev=curr;
        whilie(tmp)
        {
            if(tmp->data == curr->data)
            {
                prev->Next=tmp->Next;
                free(tmp);
                tmp=prev;/*free是指释放该指针指向的空间，也就是说空间“消失”，而指针也不再指向那一空间，变成野指针*/
            }
            tmp=tmp->Next;
        }
        curr=curr->Next;
    }
}
