#include <bits/stdc++.h>
using namespace std;

int test(stack<int> st, stack<int>& st1)
{
    int val = st.top();
    st.pop();
    if (st.empty())
        return val; 
    int ans = test(st, st1);
    st1.push(val);     
    return ans;          
}

int pop(stack<int> &st)
{
    stack<int> st1;
    int ans = test(st, st1);
    st = st1;
    return ans;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int ans = pop(st);
    cout << ans << endl;
    cout << st.top() << endl;
    cout << pop(st) << endl;
    cout << st.top() << endl;
    cout << pop(st) << endl;
    return 0;
}
