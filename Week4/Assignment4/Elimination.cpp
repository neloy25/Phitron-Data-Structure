#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> st;

        for(char c : s) {
            if(st.empty()) {
                st.push(c);
                continue;
            }

            if(c == '1') {
                if(st.top() == '0') {
                    st.pop();
                    continue;
                }
            }

            st.push(c);
        }

        cout << (st.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}

