#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    reverse(v.begin(),v.end());

    for(int val: v) cout << val << " ";
    return 0;
}