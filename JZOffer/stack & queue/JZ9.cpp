#include <iostream>
#include <stack>
using namespace std;

/** 
 * @brief 用两个栈来实现一个队列，
 *        使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 
 *        队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        while(!stack1.empty())
        {
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        
        int res = stack2.top();
        stack2.pop();
        while(!stack2.empty())
        {
            int tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};