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

void sort_list(Node * head){
    for(Node * i = head; i->next != NULL; i = i->next){
        for(Node * j = i->next; j != NULL; j = j->next){
            if(j->val > i->val){
                swap(j->val,i->val);
            }
        }
    }
}

bool check_duplicate(Node * head){
    while(head->next != NULL){
        if(head->val == head->next->val){
            return true;
        }
        head = head->next;
    }
    return false;
}



int main()
{
    Node * head = NULL; Node * tail = NULL;
    input_list(head,tail);
    sort_list(head);
    bool check = check_duplicate(head);
    cout << ( check ? "YES" : "NO");
    return 0;
}

