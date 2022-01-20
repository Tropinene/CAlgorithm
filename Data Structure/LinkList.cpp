#include <iostream>
using namespace std;

typedef int ElemType;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

// 创建空链表
ListNode* CreateList(ListNode* L)
{
    L = (ListNode*)malloc(sizeof(ListNode));
    L->next = NULL;
    
    return L;
}

// 在头结点插入元素
ListNode* List_HeadInsert(ListNode* L, int x)
{
    ListNode *s;
    
    s = new ListNode(x);
    s->next = L->next;
    L->next = s;
    delete s;
    
    return L;
}

// 在尾结点插入元素
ListNode* List_TailInsert(ListNode* L, int x)
{
    ListNode *s, *r = L;
    
    while(r->next != NULL)
        r = r->next;
    
    s = new ListNode(x);
    r->next = s;
    delete s;
    
    return L;
}

// 按序号查找结点值
ListNode *GetElem(ListNode* L, int i)
{
    int j = 1;
    ListNode *p = L->next;
    
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
ListNode *LocateElem(ListNode* L, ElemType e)
{
    ListNode *p = L->next;
    while (p != NULL && p->val != e)
    {
        p = p->next;
    }
    return p;   // 这里返回的是指针，没找到返回NULL
}

// 将结点插入到指定位置
ListNode* Insert(ListNode* L, ListNode *s, int i)
{
    ListNode *p = GetElem(L, i-1);
    s->next = p->next;
    p->next = s;
    
    return L;
}

// 删除第i个结点
ListNode* DeleteNode(ListNode* L, int i)
{
    ListNode *p = GetElem(L, i-1);
    ListNode *q = p->next;
    p->next = q->next;
    free(q);
    return L;
}

// 反转链表
ListNode* ReverseList(ListNode* pHead) {
    ListNode *tmp = NULL;
    ListNode *cur = NULL;
         
    while(pHead != NULL)
    {
        tmp = pHead->next;
        pHead->next = cur;
        cur = pHead;
        pHead = tmp;
    }
    return cur;
}

int main()
{
    return 0;
}
