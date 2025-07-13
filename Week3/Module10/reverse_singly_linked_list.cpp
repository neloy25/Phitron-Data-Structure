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

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void input_list(Node *&head, Node *&tail)
{
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, tail, val);
    }
}

void reverse_list(Node *&head, Node *&tail, Node *temp) {
    if (temp->next == NULL) {
        head = temp;
        return;
    }
    reverse_list(head, tail, temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp;
}


void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    input_list(head, tail);
    reverse_list(head,tail,head);
    print_list(head);
    return 0;
}
