#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> q;

    int n,m; cin >> n >> m;
    if(n != m) {
        cout << "NO";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        st.push(val);
    }

    for(int i = 0; i < m; i++) {
        int val; cin >> val;
        q.push(val);
    }

    for(int i = 0; i < n; i++) {
        if(st.top() != q.front()) {
            cout << "NO";
            return 0;
        }
        st.pop();
        q.pop();
    }
    cout << "YES";
    return 0;
}

