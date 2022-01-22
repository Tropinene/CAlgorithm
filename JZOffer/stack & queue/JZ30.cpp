#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief 定义栈的数据结构，
 *        请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，
 *        输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。
 */
class Solution {
public:
    stack<int> s, mins;
    void push(int value) {
        s.push(value);
        if(mins.empty() || value <= mins.top())
            mins.push(value);
    }
    void pop() {
        int tmp = s.top();
        s.pop();
        if(!mins.empty() && mins.top() == tmp)
            mins.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return mins.top();
    }
};