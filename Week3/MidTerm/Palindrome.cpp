#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node* prev;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node * &head, Node * &tail,int val){
    Node * newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode; 
}

void input_list(Node * &head, Node * &tail){
    while(true){
        int val; cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
}

bool isPalindrome(Node *head, Node * tail){
    Node * left = head;
    Node * right = tail;
    while(left != right && left->prev != right) {
        if(left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;
    input_list(head,tail);
    bool check = isPalindrome(head,tail);
    cout << (check ? "YES" : "NO");
    return 0;

}

