#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;

    // All function(6) learned in this file:
    // vec.size();
    // vec.capacity();
    // vec.empty();
    // vec.max_size(); // No use
    // vec.clear();
    // vec.resize(5);
    // vec.resize(7,30); // if greater than size we can inialize the next values


    // capacity and size function analysis
    cout << "capacity() and size():\n";
    vec.push_back(3);
    cout << vec.size() << " " << vec.capacity() << endl;
    vec.push_back(4);
    cout << vec.size() << " " << vec.capacity() << endl;
    vec.push_back(5);
    cout << vec.size() << " " << vec.capacity() << endl;
    vec.push_back(6);
    cout << vec.size() << " " << vec.capacity() << endl;
    vec.push_back(6);
    cout << vec.size() << " " << vec.capacity() << endl;

    
    // resize function analysis
    cout << "\nresize():\n";
    vec.resize(7);
    for(int val : vec) cout << val << " ";
    cout << endl;
    // Notes: 
    // In C++, when we use the resize() function on a vector to increase its size,
    // the new elements are initialized with default values.
    vec.resize(10,5);
    for(int val : vec) cout << val << " ";
    cout << endl;
    vec.resize(3);
    for(int val : vec) cout << val << " ";
    cout << endl;

    // empty and clear functon analysis
    cout << "\nempty() and clear():\n";
    cout << (vec.empty() ? "Empty" : "Not Empty") << endl;
    vec.clear();
    cout << (vec.empty() ? "Empty" : "Not Empty") << endl;


    // Happy Coding!!!!
    return 0;
}