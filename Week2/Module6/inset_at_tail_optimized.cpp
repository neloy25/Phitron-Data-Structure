#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_tail(Node * &head, Node * &tail,int val)
{
    Node *newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

int main()
{
    Node * head = new Node(10);
    Node * a = new Node(20);
    Node * b = new Node(30);
    Node * tail = new Node(40);

    head->next = a;
    a->next = b;
    b->next = tail;

    insert_at_tail(head, tail, 100);
    insert_at_tail(head, tail, 200);
    print_list(head);
    return 0;
}
