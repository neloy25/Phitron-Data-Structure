#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    sort(arr.begin(),arr.end());
    while(q--){
        int val;
        cin >> val;
        int l = 0;
        int r = n - 1;
        int flag = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] == val){
                flag = 1;
                break;
            } else if(arr[mid] > val){
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        if(flag) cout << "found\n";
        else cout << "not found\n";
    }
    return 0;

}

