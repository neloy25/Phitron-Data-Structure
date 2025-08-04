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

void level_nodes(Node * root,int x) {
    queue<Node *> q;
    q.push(root);
    int level = 0;

    while(!q.empty()) {
        int len = q.size();

        for(int i = 0; i < len; i++) {
            Node * f = q.front();
            q.pop();

            if(x == level){
                cout << f->val << " ";
            }

            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }

        if(x == level) return;
        level++;
    }

    cout << "Invalid";
}

int main()
{
    Node *root = input_tree();
    int x; cin >> x;
    level_nodes(root,x);
    return 0;
}
