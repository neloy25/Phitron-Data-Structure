#include <bits/stdc++.h>
using namespace std;

class myQueue
{
    list<int> l;

public:
    void push(int val)
    {
        l.push_back(val);
    }

    void pop()
    {
        l.pop_front();
    }

    int front()
    {
        return l.front();
    }

    int back()
    {
        return l.back();
    }

    int size()
    {
        return l.size();
    }

    bool empty()
    {
        return l.empty();
    }
};

int main()
{
    myQueue q;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    while(!q.empty()) {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }
    return 0;
}
