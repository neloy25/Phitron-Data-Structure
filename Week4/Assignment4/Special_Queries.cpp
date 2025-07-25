#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> q;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        if(n) {
            if(q.empty()) cout << "Invalid" << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        } else {
            string name; cin >> name;
            q.push(name);
        }
    }
    return 0;

}

