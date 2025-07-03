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
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void delete_at_any_pos(Node * head, Node * &tail, int idx){
    while(head->next != tail){
        head = head->next;
    }
    Node * delnode = head->next;
    tail = head;
    tail->next = NULL;
    delete delnode;
}

void print_list(Node * head)
{
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail,val);
    }
    delete_at_any_pos(head,tail,2);
    print_list(head);
    return 0;
}
