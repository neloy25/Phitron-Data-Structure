#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int val) {
    v.push_back(val);

    int i = v.size() - 1;
    int j = (i - 1) / 2;
    while(j >= 0 && v[j] < v[i]) {
        swap(v[i],v[j]);
        i = j;
        j = (i - 1) / 2;
    }
}

int main()
{
    vector<int> v = {23,15,21,13,9,19,8,2,4,7};
    insert(v,10);
    insert(v,12);
    insert(v,15);
    insert(v,14);
    insert(v,16);
    insert(v,26);
    for(int val : v) cout << val << " ";

    return 0;
}

