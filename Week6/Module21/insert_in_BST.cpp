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

void insert(Node * &root,int val) {
    if(root == NULL) {
        root = new Node(val);
        return;
    }

    if(root->val == val) return;

    if(val > root->val) insert(root->right,val);
    else insert(root->left,val);
}

void in_order_traversal(Node * root) {
    if(root == NULL) return;

    in_order_traversal(root->left);
    cout << root->val << " ";
    in_order_traversal(root->right);
}

bool search(Node * root,int val) {
    if(root == NULL) return false;
    if(root->val = val) return true;

    if(val > root->val) return search(root->right,val);
    else return search(root->left,val);
}

int main()
{   
    Node * root = NULL;
    vector<int> v = {3,1,5,2,4,4,1,3,6,10,7,8};

    for(int val: v) {
        insert(root,val);
    }

    in_order_traversal(root);
    return 0;
}
