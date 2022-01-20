#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /** 
     * @brief JZ6: 输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。
     * @attention 先遍历链表并用栈存储结点，再依次pop出结点成为新链表。
     * @param head ListNode类 
     * @return Vector<int>类
    */
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        ListNode* p = head;
        while(p != NULL) {
            s.push(p->val);
            p = p->next;
        }
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }

    /**
     * @brief JZ18: 给定单向链表的头指针和一个要删除的节点的值，
     *              定义一个函数删除该节点。返回删除后的链表的头节点。
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* bef = head;
        ListNode* cur = bef->next;
        while(bef->val == val) {    // 处理头结点就是要删除的情况
            head = cur;
            bef = head;
            cur = bef->next;
        }
        
        while(cur != NULL) {
            if(cur->val == val) {
                bef->next = cur->next;
            }
            bef = bef->next;
            cur = bef->next;
        }
        return head;
    }

    /**
     * @brief 输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。
                如果该链表长度小于k，请返回一个长度为 0 的链表。
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        int n = 0;
        ListNode *tmp = pHead;
         
        while(tmp != NULL){
            n++;
            tmp = tmp->next;
        }
         
        if(k > n) return NULL;
         
        for(int i=0; i<n-k; i++)
            pHead = pHead->next;
        return pHead;
    }

    /** 
     * @brief JZ23: 给一个长度为n链表，若其中包含环，
     *              请找出该链表的环的入口结点，否则，返回null。
     * @param pHead ListNode类 
     * @return ListNode类
    */
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        unordered_set<ListNode*> s;
        while(pHead != NULL) {
            if(s.find(pHead) == s.end()) {
                s.insert(pHead);
            }
            else
                return pHead;
            pHead = pHead->next;
        }
        return NULL;
    }

    /** 
     * @brief JZ24: 给定一个单链表的头结点pHead(该头节点是有值的)，
     *              长度为n，反转该链表后，返回新链表的表头。
     * @param pHead ListNode类 
     * @return ListNode类
    */
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
    
    /** 
     * @brief JZ25: 输入两个递增的链表，单个链表的长度为n，
     *              合并这两个链表并使新链表中的节点仍然是递增排序的。
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
    */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        
        ListNode* nHead;
        // 确定表头
        if(pHead1->val < pHead2->val) {
            nHead = pHead1;
            pHead1 = pHead1->next;
        }
        else {
            nHead = pHead2;
            pHead2 = pHead2->next;
        }
        ListNode* p = nHead;
            
        while(pHead1 != NULL && pHead2 != NULL) {
            ListNode* tmp;
            if(pHead1->val < pHead2->val) {
                tmp = pHead1;
                pHead1 = pHead1->next;
            }
            else {
                tmp = pHead2;
                pHead2 = pHead2->next;
            }
            p->next = tmp;
            p = tmp;
        }
        if(pHead1 != NULL)
            p->next = pHead1;
        if(pHead2 != NULL)
            p->next = pHead2;
        
        return nHead;
    }

    /** 
     * @brief JZ52: 输入两个无环的单向链表，找出它们的第一个公共结点，
     *              如果没有公共节点则返回空。
     * @attention 这道题写得很涝，用一个unordered_set存了一个链表的元素，
     *              再用find()比较有没有出现过的元素。   
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
    */
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unordered_set<ListNode*> s;
        ListNode* tmp = pHead1;
         
        while(tmp != NULL)
        {
            s.insert(tmp);
            tmp = tmp->next;
        }
        tmp = pHead2;
        while(tmp != NULL)
        {
            if(s.find(tmp) != s.end())
                return tmp;
            tmp = tmp->next;
        }
        return NULL;
    }

    /** 
     * @brief JZ76: 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
     *              重复的结点不保留，返回链表头指针。 
     *              例如，链表 1->2->3->3->4->4->5  处理后为 1->2->5
     * @param pHead ListNode类 
     * @return ListNode类
    */
    ListNode* deleteDuplication(ListNode* pHead) {
        vector<int> arr(1000,0);
        vector<int> num;
        while(pHead != NULL) {
            num.push_back(pHead->val);
            arr[pHead->val]++;
            pHead = pHead->next;
        }
        
        ListNode* nHead = (ListNode*)malloc(sizeof(ListNode));
        ListNode* p = nHead;
        for(auto it : num) {
            if(arr[it] == 1) {
                ListNode* tmp = new ListNode(it);
                p->next = tmp;
                p = tmp;
            }
        }
        return nHead->next;
    }

};