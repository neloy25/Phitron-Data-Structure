#include<bits/stdc++.h>
using namespace std;

class myStack{
    list<int> l;

public:
    void push(int val) {
        l.push_back(val);
    }

    void pop(){
        l.pop_back();
    }

    int top() {
        return l.back();
    }

    int size() {
        return l.size();
    }

    bool empty() {
        return l.empty();
    }
};

int main()
{
   myStack st;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st.push(val);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

