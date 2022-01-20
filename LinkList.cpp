#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// 创建空链表
LinkList CreateList(LinkList L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    
    return L;
}

LNode *CreateNode(ElemType x)
{
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    
    return s;
}

// 在头结点插入元素
LinkList List_HeadInsert(LinkList L, int x)
{
    LNode *s;
    
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
    
    return L;
}

// 在尾结点插入元素
LinkList List_TailInsert(LinkList L, int x)
{
    LNode *s, *r = L;
    
    while(r->next != NULL)
        r = r->next;
    
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    r->next = s;
    
    return L;
}

// 按序号查找结点值
LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    
    if(i == 0)  return L;
    if(i < 0)   return NULL;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;   // 这里返回的是指针，没找到返回NULL
}

// 将结点插入到指定位置
LinkList Insert(LinkList L, LNode *s, int i)
{
    LNode *p = GetElem(L, i-1);
    s->next = p->next;
    p->next = s;
    
    return L;
}

// 删除第i个结点
LinkList DeleteNode(LinkList L, int i)
{
    LNode *p = GetElem(L, i-1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return L;
}

int main()
{
    return 0;
}
