#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mid = (n + 1) / 2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == mid && j == mid) {
                cout << 'X';
            } else if(i == j) {
                cout << '\\';
            } else if(i + j == n + 1) {
                cout << '/';
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;

}

