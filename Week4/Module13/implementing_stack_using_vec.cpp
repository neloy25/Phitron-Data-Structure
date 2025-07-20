#include<bits/stdc++.h>
using namespace std;

class myStack{
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop(){
        v.pop_back();
    }

    int top() {
        return v.back();
    }

    int size() {
        return v.size();
    }

    bool empty() {
        return v.empty();
    }
};

int main()
{
    myStack s;

    if(s.empty()) cout << "Empty";

    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.pop();
    cout << s.top();


    return 0;
}

