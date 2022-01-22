#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        
        int index = 0;
        for(int i=0; i<pushV.size(); i++) {
            s.push(pushV[i]);
            while(!s.empty() && s.top() == popV[index]) {
                s.pop();
                index++;
            }
        }
        
        return s.empty();
    }
};

int main() {
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,5,3,2,1};
    Solution s;

    cout << s.IsPopOrder(pushV, popV) << endl;
    return 0;
}