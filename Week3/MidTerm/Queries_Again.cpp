#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
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

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << ' ';
        temp = temp->next;
    }
}

void print_backward(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << ' ';
        temp = temp->prev;
    }
}

void print_list(Node *head, Node * tail){
    cout << "L -> ";
    print_forward(head);
    cout << endl << "R -> ";
    print_backward(tail);
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int len = 0;

    int t;
    cin >> t;
    while(t--){
        int x,v; cin >> x >> v;
        if(x > len) cout << "Invalid" << endl;
        else if(x == 0) {
            insert_at_head(head,tail,v);
            len++;
            print_list(head,tail);
        } else if(x == len) {
            insert_at_tail(head,tail,v);
            len++;
            print_list(head,tail);
        } else {
            insert_at_any_pos(head,v,x);
            len++;
            print_list(head,tail);
        }
    }
    return 0;
}
