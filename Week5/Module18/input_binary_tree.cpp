#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    queue<Node *> q;
    int v;
    cin >> v;
    Node *root = new Node(v);
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        int l, r;
        cin >> l >> r;
        Node *left_node = new Node(l);
        Node *right_node = new Node(r);
        q.pop();

        if (l != -1)
        {
            f->left = left_node;
            q.push(left_node);
        }
        if (r != -1)
        {
            f->right = right_node;
            q.push(right_node);
        }
    }
    return root;
}

void level_order(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree doesn't exist" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        cout << f->val << " ";
        q.pop();

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

int main()
{
    Node *root = input_tree();
    level_order(root);
    return 0;
}
