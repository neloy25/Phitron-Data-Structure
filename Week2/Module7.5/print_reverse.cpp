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

void reverse_list(Node * head,Node * &rev_head, Node * & rev_tail){
    if(head == NULL) return;
    reverse_list(head->next,rev_head,rev_tail);
    insert_at_tail(rev_head,rev_tail,head->val);
}

void print_list(Node * head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    Node * head = NULL; Node * tail = NULL;
    Node * rev_head = NULL; Node * rev_tail = NULL;
    input_list(head,tail);
    reverse_list(head,rev_head,rev_tail);
    print_list(rev_head);
    return 0;
}

