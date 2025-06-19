#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    // All function(2) learned in this file
    // replace(v.begin(),v.end(), val, replaced_val);
    // find(v.begin(),v.end(),val); -it doesn't work with index

        
    vector<int> v1 = {1,2,3,2,5,2,3};
  
    // replace() 
    cout << "Replace\n";
    replace(v1.begin(),v1.end(),3,10);
    for(int i: v1) cout << i << " ";
    cout << endl;
    replace(v1.begin(),v1.end()-2,2,12);
    for(int i: v1) cout << i << " ";
    cout << endl;

    // find()
    cout << "\nFind:\n" ;
    vector<int>:: iterator it = find(v1.begin(),v1.end(),5);
    if(it == v1.end()) cout << "Not Found\n";
    else cout << "Found " << *it;

    return 0;
}