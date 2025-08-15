#include <bits/stdc++.h>
using namespace std;

bool binary_search(const vector<int> &v, int val, int l, int r) {
    if (l > r) return false; 
    
    int mid = (l + r) / 2;
    
    if (v[mid] == val) return true;
    else if (v[mid] > val)
        return binary_search(v, val, l, mid - 1);
    else
        return binary_search(v, val, mid + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    vector<int> pre_sum(n);
    pre_sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre_sum[i] = pre_sum[i - 1] + v[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (pre_sum[i] == k) res++;

        if (binary_search(pre_sum, pre_sum[i] + k, 0, n - 1)) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
