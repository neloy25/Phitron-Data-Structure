#include<stdio.h>
#include<vector>

using namespace std;

int main(){
    vector<int> vec;
    vec.size();
    vec.capacity();
    vec.empty();
    vec.max_size();
    vec.clear();
    vec.resize(5); // if less
    vec.resize(7,30); // if greater than size
    return 0;
}