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

Node *convert_tree(vector<int> v, int n, int l, int r)
{
    if(l > r) return NULL;
    int mid = (l + r) / 2;
    Node * root = new Node(v[mid]);

    Node * left_node = convert_tree(v,n,l,mid - 1);
    Node * right_node = convert_tree(v,n,mid + 1,r);

    root->left = left_node;
    root->right = right_node;

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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    sort(v.begin(),v.end());
    Node *root = convert_tree(v, n, 0, n - 1);
    level_order(root);
    return 0;
}
