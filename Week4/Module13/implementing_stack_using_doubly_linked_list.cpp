#include <bits/stdc++.h>
using namespace std;

class myStack
{
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

    void delete_at_tail(Node *&tail)
    {
        Node *delnode = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete delnode;
    }

    Node * head = NULL;
    Node * tail = NULL;

public:

    void push(int val) {
        insert_at_tail(head,tail,val);
    }

    void pop(){
        delete_at_tail(tail);
    }

    int top() {
        return l.back();
    }

    int size() {
        return l.size();
    }

    bool empty() {
        return l.empty();
    }
};
