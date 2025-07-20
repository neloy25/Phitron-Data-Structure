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

    void delete_at_tail(Node *&head, Node *&tail)
    {
        Node *delnode = tail;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            delete delnode;
            return;
        }
        tail = tail->prev;
        tail->next = NULL;
        delete delnode;
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
        delete_at_tail(head, tail);
        len--;
    }

    int top()
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
    myStack st;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    while (!st.empty())
    {
        cout << st.top() << " " << st.size() << endl;
        st.pop();
    }
    return 0;
}
