#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node * prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(Node * &head, Node * &tail,int val){
    Node * newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insert_at_any_pos(Node * &head,int val,int idx){
    Node * newnode = new Node(val);
    Node * temp = head;
    for(int i = 0; i < idx - 1; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;

    temp = newnode->next;
    temp->prev = newnode;
}

void print_forward(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->val << ' ';
        temp = temp->next;
    }
}

void print_backward(Node * tail){
    Node * temp = tail;
    while(temp != NULL){
        cout << temp->val << ' ';
        temp = temp->prev;
    }
}

int main()
{
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * tail = new Node(30);

    head->next = a;
    a->prev = head;

    a->next = tail;
    tail->prev = a;

    insert_at_head(head,tail,5);
    insert_at_head(head,tail,0);

    insert_at_any_pos(head,100,3);
    print_forward(head);
    cout << endl;
    print_backward(tail);

    return 0;

}



