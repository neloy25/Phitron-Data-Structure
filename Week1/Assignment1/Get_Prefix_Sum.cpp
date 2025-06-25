#include<bits/stdc++.h>
using namespace std;

int main()
{    
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<long long> prefix_sum(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    prefix_sum[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    for(int i = n - 1; i >= 0; i--){
        cout << prefix_sum[i] << " ";
    }
    return 0;

}

