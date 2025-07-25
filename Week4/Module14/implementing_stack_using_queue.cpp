#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    MyStack(){}

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        queue<int> q1;
        int val;
        while (true)
        {
            val = q.front();
            q.pop();
            if(q.empty()) {
                break;
            }
            q1.push(val);
        }
        q = q1;
        return val;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{

    return 0;
}
