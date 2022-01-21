#include <iostream>
using namespace std;

#define MaxSize 50

typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int top;
}SqStack;

class bracketMatching {
    private:
        SqStack S;
    public:
        void InitStack() {
            S.top = -1;
        }

        bool StackEmpty() {
            if(S.top == -1) return true;
            else    return false;
        }

        bool Push(ElemType x) {
            if(S.top == MaxSize - 1)
                return false;
            
            S.data[++S.top] = x;
            return true;
        }

        bool Pop(ElemType &x) {
            if(S.top == -1)
                return false;
            
            x = S.data[S.top--];
            return true;
        }

        bool GetTop(ElemType &x) {
            if(S.top == -1)
                return false;

            x = S.data[S.top];
            return true;
        }
};

int main() {
    bracketMatching BM;
    BM.InitStack();
    string str;
    cin >> str;

    for(int i=0; i<str.length(); i++) {
        ElemType tmp;
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            BM.Push(str[i]);
        }
        else if(str[i] == ')') {
            BM.GetTop(tmp);
            if(tmp == '(')
                BM.Pop(tmp);
            else {
                cout << "no" << endl;
                break;
            }
        }
        else if(str[i] == '}') {
            BM.GetTop(tmp);
            if(tmp == '{')
                BM.Pop(tmp);
            else {
                cout << "no" << endl;
                break;
            }
        }
        else if(str[i] == ']') {
            BM.GetTop(tmp);
            if(tmp == '[')
                BM.Pop(tmp);
            else {
                cout << "no" << endl;
                break;
            }
        }
    }

    if(BM.StackEmpty())
        cout << "yes" << endl;

    return 0;
}