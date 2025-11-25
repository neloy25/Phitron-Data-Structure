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


int list_len(Node * head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

int val_at_index(Node * head,int idx){
    for(int i = 0; i < idx; i++){
        head = head->next;
    }
    return head->val;
}


int main()
{
    Node * head = NULL; Node * tail = NULL;
    input_list(head,tail);

    int len = list_len(head);
    if(len % 2 == 1){
        cout << val_at_index(head, len / 2);
    } else{
        cout << val_at_index(head, len / 2 - 1) << " " << val_at_index(head, len / 2);
    }
    return 0;
}

