#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        map<string,int> mp;
        pair<string,int> mx;
        mx.second = 0;
        string s;
        getline(cin,s);
        stringstream ss(s);
        string word;
        while(ss >> word) {
            mp[word]++;
            if(mp[word] > mx.second) {
                mx.first = word;
                mx.second = mp[word];
            }
        }

        cout << mx.first << " " << mx.second << endl;
    }
    return 0;

}

