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

int list_len_helper(Node * head, int i){
    if(head == NULL) return i;
    return list_len_helper(head->next, i + 1);
}

int list_len(Node * head){
    return list_len_helper(head, 0);
}


int main()
{
    Node * head = NULL; Node * tail = NULL;
    input_list(head,tail);

    int len = list_len(head);
    cout << len;
    return 0;
}

