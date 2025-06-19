#include<iostream>
#include<vector>
using namespace std;

int main(){

    // Vector iterators
    // v.begin() -it indicates the first val
    // v.end() -it indicates the next of last value
    vector<int> v= {1,2,3,4,5};

    for(auto it = v.begin(); it < v.end(); it++){
        cout << *it << " ";
    }

    return 0;
}