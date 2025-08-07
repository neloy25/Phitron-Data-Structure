#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int roll;
    int marks;

    Student(string name,int roll,int marks) {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp{
public:
    bool operator()(Student l, Student r){
        if(l.marks == r.marks) return l.roll > r.roll;
        return l.marks < r.marks;
    }
};

int main()
{
    priority_queue<Student,vector<Student>,cmp> q;
    int n;
    cin >> n;
    while(n--){
        string name;
        int roll,marks;
        cin >> name >> roll >> marks;
        Student obj(name,roll,marks);
        q.push(obj);
    }

    int t;
    cin >> t;
    while(t--){
        int cmd; cin >> cmd;
        if(cmd == 0) {
            string name;
            int roll,marks;
            cin >> name >> roll >> marks;
            Student obj(name,roll,marks);
            q.push(obj);
            cout << q.top().name << " " << q.top().roll << " " << q.top().marks << endl;
        } else if(cmd == 1) {
            if(q.empty()) cout << "Empty" << endl;
            else cout << q.top().name << " " << q.top().roll << " " << q.top().marks << endl;
        } else{
            if(q.empty()) {
                cout << "Empty" << endl;
                continue;
            }
            q.pop();
            if(q.empty()) cout << "Empty" << endl;
            else cout << q.top().name << " " << q.top().roll << " " << q.top().marks << endl;
        }
    }
    return 0;

}

