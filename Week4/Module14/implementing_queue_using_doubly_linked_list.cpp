#include <bits/stdc++.h>
using namespace std;

class myQueue
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

    void delete_at_head(Node *&head, Node *&tail)
    {
        Node *delnode = head;
        head = head->next;
        delete delnode;
        if(head == NULL) {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }

    Node *head = NULL;
    Node *tail = NULL;
    int len = 0;

public:
    void push(int val)
    {
        insert_at_tail(head, tail, val);
        len++;
    }

    void pop()
    {
        delete_at_head(head, tail);
        len--;
    }

    int front()
    {
        return head->val;
    }

    int back()
    {
        return tail->val;
    }

    int size()
    {
        return len;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    myQueue q;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    while (!q.empty())
    {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }
    return 0;
}
