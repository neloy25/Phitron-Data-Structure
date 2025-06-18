#include<stdio.h>
#include<vector>

using namespace std;

int main(){
    int n = 10;
    vector<int> v1;
    vector<int>v2(n);
    vector<int>v3(n,0);
    vector<int> v4 = {1,2,3,4,5};
    vector<int> v5(v4);
    int arr[5] = {5,4,3,2,1};
    vector <int> v6(arr,arr+5);
    return 0;
}