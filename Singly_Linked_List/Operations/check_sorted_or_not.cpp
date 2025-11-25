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

bool check_sorted(Node * head){
    while(head->next != NULL){
        if(head->val > head->next->val){
            return false;
        }
        head = head->next;
    }
    return true;
}



int main()
{
    Node * head = NULL; Node * tail = NULL;
    input_list(head,tail);
    bool check = check_sorted(head);
    cout << ( check ? "YES" : "NO");
    return 0;
}

