#include<bits/stdc++.h>
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

void count_leaf_nodes(Node *root,vector<int> &feq)
{
    if (root == NULL)
        return;
    if(root->left == NULL && root ->right == NULL) {
        feq[root->val]++;
        return;
    }
    count_leaf_nodes(root->left,feq);
    count_leaf_nodes(root->right,feq);
}

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node * root = input_tree();
    vector<int> feq(101,0);
    count_leaf_nodes(root,feq);

    int mx = 0;
    int val = 0;
    for(int i= 0; i < 101;i++) {
        if(feq[i] > mx) {
            mx = feq[i];
            val = i;
        }
    }

    cout << val << endl;
    return 0;
}

