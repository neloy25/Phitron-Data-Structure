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

void level_order(Node * root) {
    if(root == NULL) {
        cout << "Tree doesn't exist" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        Node * f = q.front();
        cout << f->val << " ";
        q.pop();

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node * root = input_tree();

    queue<Node *> q;
    queue<Node *> q1;

    q.push(root);
    q1.push(root);
    int cousin = 0;

    while(!q.empty()) {
        while(!q1.empty()) {
            Node * f = q1.front();
            if(f->val == -2) {
                if(cousin > 2) f->val = cousin - 2;
                else f->val = 0;
            } else{
                if(cousin) f->val = cousin - 1;
                else f->val = cousin;
            }
            q1.pop();
        }

        cousin = 0;
        int len = q.size();

        for(int i = 0; i < len; i++) {
            Node * f = q.front();
            q.pop();

            if(f->left && f->right) {
                cousin+=2;
                f->left->val = -2;
                f->right->val = -2;
                q.push(f->left);
                q.push(f->right);
            }
            else if(f->left) {
                cousin++;
                q.push(f->left);
            } else if (f->right){
                cousin++;
                q.push(f->right);
            }
        }

        q1 = q;
    }

    level_order(root);
    return 0;
}

