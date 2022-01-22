#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 给定一个长度为 n 的数组 num 和滑动窗口的大小 size ，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， 
 * {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 
 */
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if(size == 0)
            return res;
        int index = 0;
        
        for(;index+size<=num.size();index++) {
            int max = -1;
            for(int i=index; i<index+size; i++) {
                if(num[i] > max)
                    max = num[i];
            }
            res.push_back(max);
            max = -1;
        }
        return res;
    }
};

int main() {
    vector<int> input = {2,3,4,2,6,2,5,1};
    cout << "[Input] = {2,3,4,2,6,2,5,1}" << endl;

    Solution solution;
    vector<int> output = solution.maxInWindows(input, 3);
    cout << "[Output] = {" << output[0];
    for(int i=1; i<output.size();i++)
        cout << "," << output[i];
    cout << "}\n";
}