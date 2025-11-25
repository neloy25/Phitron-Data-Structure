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

int max_val(Node * head){
    int mx = head->val;
    while(head != NULL){
        if(head->val > mx) mx = head->val;
        head = head->next; 
    }
    return mx;
}


int main()
{
    Node * head = NULL; Node * tail = NULL;
    input_list(head,tail);
    int mx = max_val(head);
    cout << mx << endl;
    return 0;
}

