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

void insert_at_any_pos(Node * head, int idx, int val){
    Node * newnode = new Node(val);
    for(int i = 0; i < idx - 1; i++){
        head = head->next;
    }
    newnode->next = head->next;
    head->next = newnode;
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

void print_list(Node * head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
}


int main()
{
    Node * head = NULL; Node * tail = NULL;
    input_list(head,tail);
    int len = list_len(head,0);
    int q; cin >> q;
    while(q--){
        int idx,val; cin >> idx >> val;
        if(idx < 0 || idx > len){
            cout << "Invalid";
        } else if(idx == 0) {
            insert_at_head(head,tail,val);
            len++;
            print_list(head);
        } else if(idx == len){
            insert_at_tail(head,tail,val);
            len++;
            print_list(head);
        } else{
            insert_at_any_pos(head,idx,val);
            len++;
            print_list(head);
        }
        cout << endl;
    }
    return 0;
}

