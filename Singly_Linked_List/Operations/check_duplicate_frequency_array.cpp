#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node * next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};


void insert_at_tail(Node * &head, Node * &tail,int val){
    Node * newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void input_list(Node * &head, Node * &tail){
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
}

bool check_duplicate(Node * head){
    vector<int> feq(100,0);
    while(head != NULL){
        feq[head->val]++;
        head = head->next;
    }
    for(int i = 0; i < 100; i++){
        if(feq[i] > 1) {
            return true;
        }
    }
    return false;
}



int main()
{
    Node * head = NULL; Node * tail = NULL;
    input_list(head,tail);
    bool check = check_duplicate(head);
    cout << ( check ? "YES" : "NO");
    return 0;
}

