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

void reverse_sub_list(Node *&newhead, Node *&newtail, Node *end, Node *tmp)
{
    if (tmp == end)
    {
        insert_at_tail(newhead, newtail, tmp->val);
        return;
    }
    reverse_sub_list(newhead, newtail, end, tmp->next);
    insert_at_tail(newhead, newtail, tmp->val);
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
    int left, right;
    cin >> left >> right;

    if (head == NULL && left == right)
    {
        print_list(head);
        return 0;
    }
    Node *newhead = NULL;
    Node *newtail = NULL;
    Node *tmp = head;
    for (int i = 1; i < left; i++)
    {
        insert_at_tail(newhead, newtail, tmp->val);
        tmp = tmp->next;
    }
    Node *start = tmp;
    for (int i = left; i < right; i++)
    {
        tmp = tmp->next;
    }
    Node *end = tmp;

    reverse_sub_list(newhead, newtail, end, start);
    tmp = tmp->next;
    while (tmp != NULL)
    {
        insert_at_tail(newhead, newtail, tmp->val);
        tmp = tmp->next;
    }
    print_list(newhead);
    return 0;
}
