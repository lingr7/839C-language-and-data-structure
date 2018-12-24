/*
	Name: 特殊在不能使用临时的结点缓冲区 
	Copyright: 
	Author: 
	Date: 15/12/18 21:44
	Description: 
	四、写函数定义
定义函数sortLinkedList(h)，
其将h所指的一个单项链表
按照节点中存放的字符串值的字典升序排序，
返回指向排序后的第一个节点的指针。
不能使用临时的结点缓冲区。
函数原型为：NODE* sortLinkedList(char *data;struct Node *next;)NODE;
其中data指向不等长的字符数组表示的字符串。
*/

typedef struct Node{
    char *data;
    struct Node *next;
}Node;

Node* sortLinkedList(Node *h)
{
    if(!h->next)
    {
        return h;
    }
    Node *node = h, *l = NULL, *r = NULL, *rnode = NULL, *lnode = NULL, *hr = h;
    /*比头结点小的放左子链表，大的放右子链表*/
    while(node->next)
    {
        if(*h->data - *node->next->data > 0)//- -取指符号
        {
            if(!l)
            {
                l = lnode = node->next;//初始化子链头结点和构建节点
            }
            else
            {
                lnode->next = node->next;
                lnode = lnode->next;
            }
            node = node->next;
        }
        else if(*h->data - *node->next->data == 0)
        {
            hr->next = node->next;
            hr = hr->next;
            node = node->next;
        }
        else
        {
            if(!r)
            {
                r = rnode = node->next;
            }
            else
            {
                rnode->next = node->next;
                rnode = rnode->next;
            }
            node = node->next;
        }
    }
    lnode->next = NULL;//截断子链表
    rnode->next = NULL;
    /*递归排序子链并链接原头结点*/
    if(l)
    {
        l = sortLinkedList(l);
        lnode = l;
        while(lnode->next)
        {
            lnode = lnode->next;
        }
        lnode->next = h;
    }
    else
    {
        l = h;
    }
    if(r)
    {
        r = sortLinkedList(r);
    }
    hr->next = r;
    return l;
}

void PrintList(Node *h)
{
    while(h)
    {
        printf("%c", *h->data);
        h = h->next;
    }
    putchar('\n');
}

Node* newNode()
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = (char*)malloc(sizeof(char));//data也是指针也要分配内存才能赋值
    node->next = NULL;
    return node;
}

char getChar()
{
    char c;
    while((c = (char)getchar()) <= ' ');
    return c;
}

Node* CreateLinkedList()
{
    Node *prenode = newNode();
    Node *h = prenode, *node = NULL;
    int n;
    scanf("%d", &n);
    *prenode->data = getChar();
    for (int i = 1; i<n; ++i)
    {
        node = newNode();
        *node->data = getChar();
        prenode->next = node;
        prenode = node;
        node = node->next;
    }
    return h;
}

int main()
{
    Node* h = CreateLinkedList();
    PrintList(h);
    h = sortLinkedList(h);
    PrintList(h);
}
//5 d b a c e
