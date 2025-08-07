#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int n;
    cin >> n;
    while(n--){
        int val; cin >> val;
        min_heap.push(val);
    }

    int q;
    cin >> q;
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 0) {
            int x; cin >> x;
            min_heap.push(x);
            cout << min_heap.top() << endl;
        } else if(cmd == 1) {
            if(min_heap.empty()) cout << "Empty" << endl;
            else cout << min_heap.top() << endl;
        } else{
            if(min_heap.empty()) {
                cout << "Empty" << endl;
                continue;
            }
            min_heap.pop();
            if(min_heap.empty()) cout << "Empty" << endl;
            else cout << min_heap.top() << endl;
        }
    }
    return 0;

}

