#include<bits/stdc++.h>
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

class myQueue
{
public:
    int len = 0;
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

class myStack
{
public:
    int len = 0;
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
    myQueue q;

    int n,m; cin >> n >> m;
    if(n != m) {
        cout << "NO";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        st.push(val);
    }

    for(int i = 0; i < m; i++) {
        int val; cin >> val;
        q.push(val);
    }

    for(int i = 0; i < n; i++) {
        if(st.top() != q.front()) {
            cout << "NO";
            return 0;
        }
        st.pop();
        q.pop();
    }
    cout << "YES";
    return 0;
}

