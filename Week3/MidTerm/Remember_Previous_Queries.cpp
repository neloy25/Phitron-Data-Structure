#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    list<int> rev_l ;

    int n; cin >> n;
    while(n--){
        int x , v; cin >> x >> v;
        if(x == 0) l.push_front(v);
        else if(x == 1) l.push_back(v);
        else{
            if(v < l.size()) {
                l.erase(next(l.begin(),v));
            }
        }
        rev_l = l;
        reverse(rev_l.begin(),rev_l.end());
        cout << "L -> ";
        for(int val : l) cout << val << " ";
        cout << endl;
        cout << "R -> ";
        for(int val : rev_l) cout << val << " ";
        cout << endl;
    }
    return 0;

}

