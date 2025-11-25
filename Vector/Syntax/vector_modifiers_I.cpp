#include<iostream>
#include<vector>
using namespace std;

int main(){

    // All function(6) learned in this file
    // Vector assign
    // push_back(val)
    // pop_back()
    // insert(pos,val);
    // erase(pos) - single value 
    // erase(start,end+1) -multiple value

    vector<int> v= {1,2,3,4,5};
    vector<int> v1;
    vector<int> copy = {14,15,16};

    // Assign
    cout << "Assign: ";
    v1 = v; // or v1.assign(v);
    for(int val: v1) cout << val << " ";
    cout << endl;

    // push_back() & pop_back()
    v1.push_back(6);
    cout << "\nPush back\n";
    for(int val: v1) cout << val << " ";
    cout << endl;
    cout << "\nPop back\n";
    v1.pop_back();
    for(int val: v1) cout << val << " ";
    cout << endl;

    // insert()
    cout << "\nInsert\n";
    v.insert(v.begin() + 2,7);
    for(int val: v) cout << val << " ";
    cout << endl;
    v.insert(v.end() - 1,copy.begin(),copy.end());
    for(int val : v) cout << val << " ";
    cout << endl;

    // erase()
    cout << "\nErase\n";
    v.erase(v.begin() + 2);
    for(int val : v) cout << val << " ";
    cout << endl;
    v.erase(v.begin()+4,v.begin()+7);
    for(int val : v) cout << val << " ";
    cout << endl;
}