#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node* prev;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node * &head, Node * &tail,int val){
    Node * newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode; 
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

    insert_at_tail(head, tail,100);  
    insert_at_tail(head, tail,1000);  
    print_forward(head);
    cout << endl;
    print_backward(tail);
    return 0;

}

