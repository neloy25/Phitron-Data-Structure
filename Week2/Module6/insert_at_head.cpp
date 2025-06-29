#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node * &head,int val){
    Node * newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void print_list(Node * head){
    while(head != NULL){
        cout << head->val << endl;
        head = head->next;
    }
}

int main()
{
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * b = new Node(30);
    Node * c = new Node(40);

    head->next= a;
    a->next = b;
    b->next = c;

    insert_at_head(head,100);
    print_list(head);
    return 0;

}

