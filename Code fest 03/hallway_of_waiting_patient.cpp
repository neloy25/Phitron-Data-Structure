#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    queue<string> q;
    int cnt = 0;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s == "ARRIVE") {
            string t;
            cin >> t;
            q.push(t);
            cnt++;
        } else if(s == "FIRST") {
            if(q.empty()) {
                cout << "No patients" << endl;
                continue;
            }
            cout << q.front() << endl;
        } else if(s == "LAST") {
            if(q.empty()) {
                cout << "No patients" << endl;
                continue;
            }
            cout << q.back() << endl;
        } else if(s == "COUNT") {
            cout << cnt << endl;
        } else if(s == "SERVE") {
            if(q.empty()) {
                cout << "No patients" << endl;
                continue;
            }
            q.pop();
            cnt--;
        } else {
            if(q.empty()) {
                cout << "No patients" << endl;
                continue;
            }
            queue<string> q1;

            while(!q.empty()) {
                cout << q.front() << " ";
                q1.push(q.front());
                q.pop();
            }
            cout << endl;
            q = q1;
        }

    }
    return 0;
}

