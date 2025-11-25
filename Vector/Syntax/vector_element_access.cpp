#include<iostream>
#include<vector>
using namespace std;

int main(){

    // Element Access functions
    // v[i]
    // v.at(i) - will not use this
    // v.front()
    // v.back()

    vector <int> v = {1,2,3,4,5};

    cout << v[3] << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    return 0;
}