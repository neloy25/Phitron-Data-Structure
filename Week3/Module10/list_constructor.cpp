#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v = {10,20,30};
    
    list<int> l = {1,2,3,4,5};
    list<int> l1;
    list<int> l2(5);
    list<int> l3(6,0);
    list<int> l4(l);
    list<int> l5(v.begin(),v.end());
    return 0;

}

