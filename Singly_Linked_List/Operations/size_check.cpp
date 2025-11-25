#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node * next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};


void insert_at_tail(Node * &head, Node * &tail,int val){
    Node * newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void input_list(Node * &head, Node * &tail){
    int val;
    while(true){
        cin >> val;
        if(val == -1){
            break;
        }
        insert_at_tail(head, tail, val);
    }
}

int list_len(Node * head,int i){
    if(head == NULL) return i;
    return list_len(head->next,i + 1);
}


int main()
{
    Node * head1 = NULL; Node * tail1 = NULL;
    Node * head2 = NULL; Node * tail2 = NULL;
    input_list(head1,tail1);
    input_list(head2,tail2);

    int len1 = list_len(head1,0);
    int len2 = list_len(head2,0);
    if(len1 == len2) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

