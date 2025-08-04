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
    if (v == -1)
    {
        Node *root = NULL;
        return root;
    }
    Node *root = new Node(v);
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            Node *left_node = new Node(l);
            f->left = left_node;
            q.push(left_node);
        }
        if (r != -1)
        {
            Node *right_node = new Node(r);
            f->right = right_node;
            q.push(right_node);
        }
    }

    return root;
}

void outer_left(Node * root) {
    if(root == NULL) return;
    if(root->left) outer_left(root->left);
    else outer_left(root->right);
    cout << root -> val << " ";
}

void outer_right(Node * root) {
    if(root == NULL) return;
    cout << root -> val << " ";
    if(root->right) outer_right(root->right);
    else outer_right(root->left);
}

int max_depth(Node * root) {
    if(root == NULL) return 0;
    int l = max_depth(root->left);
    int r = max_depth(root->right);

    return max(l,r) + 1;
}

int main()
{
    Node *root = input_tree();
    outer_left(root->left);
    cout << root->val << " ";
    outer_right(root->right);
    return 0;
}
