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

void insert_at_head(Node * &head, Node * &tail, int val){
    Node * newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

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

void delete_at_head(Node * &head){
    Node * delnode = head;
    head = head->next;
    delete delnode;

}

void delete_at_any_pos(Node * head, Node * &tail, int idx){
    for(int i = 0; i < idx - 1; i++){
        head = head->next;
    }
    Node * delnode = head->next;
    if(head->next == tail) tail = head;
    head->next = head->next->next;
    delete delnode;
}

void print_list(Node * head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
}


int main()
{
    Node * head = NULL; Node * tail = NULL;
    int len = 0;
    int q; cin >> q;
    while(q--){
        int x,v; cin >> x >> v;
        if(x == 0){
            insert_at_head(head,tail,v);
            print_list(head);
            len++;
        } else if(x == 1){
            insert_at_tail(head,tail,v);
            print_list(head);
            len++;
        } else{
            if(len == 0 || v >= len){
                print_list(head);
            }
            else if(v == 0){
                delete_at_head(head);
                print_list(head);
                len--;
            } else{
                delete_at_any_pos(head,tail,v);
                print_list(head);
                len--;
            }
        }
        cout << endl;
    }
    return 0;
}

