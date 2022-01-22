#include <iostream>
#include <stack>
using namespace std;

/**
 * @brief 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
 *      同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
 *      例如，“nowcoder. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
 *      正确的句子应该是“I am a nowcoder.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
 * 
 */
class Solution {
public:
    string ReverseSentence(string str) {
        int l=0, r=1;
        
        if(str.find(" ") == str.npos)
            return str;
        
        stack<string> s;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == ' ' || i == str.size()-1)
            {
                r = i;
                string tmp;
                if(l == 0)
                    tmp = str.substr(l, r-l);
                else if(i == str.size()-1)
                    tmp = str.substr(l, r-l+1) + " ";
                else
                    tmp = str.substr(l, r-l+1);
                s.push(tmp);
                l = r + 1;
            }
        }
        
        string res = "", tmp;
        while(!s.empty())
        {
            tmp = s.top();
            res += tmp;
            s.pop();
        }
        return res;
    }
};

int main() {
    string s = "nowcoder. a am I";
    Solution t;
    cout << "[input] = " << s << endl;
    cout << "[output] = " << t.ReverseSentence(s) << endl;
    return 0;
}