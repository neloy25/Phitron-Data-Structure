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

bool search(Node * root,int val) {
    if(root == NULL) return false;
    if(root->val = val) return true;

    if(val > root->val) return search(root->right,val);
    else return search(root->left,val);
}

int main()
{   
    Node * root = input_tree();
    if(search(root,5)) cout << "Found";
    else cout << "Not Found";
    return 0;
}
