#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int roll;

    Student(string name,int roll) {
        this->name = name;
        this->roll = roll;
    }
};

class cmp{
public:
    bool operator()(Student l, Student r){
        if(l.name == r.name) return l.roll < r.roll;
        return l.name > r.name;
    }
};

int main()
{
    priority_queue<Student,vector<Student>,cmp> q;
    int t;
    cin >> t;
    while(t--){
        string name;
        int roll;
        cin >> name >> roll;
        Student obj(name,roll);
        q.push(obj);
    }

    while(!q.empty()) {
        Student curr = q.top();
        cout << curr.name << " " << curr.roll << endl;
        q.pop();
    }
    return 0;

}

