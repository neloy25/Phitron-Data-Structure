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

void delete_at_any_pos(Node * &head, int idx){
    Node * temp = head;
    for(int i = 0; i < idx; i++){
        temp = temp->next;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
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

void print_forward(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->val << ' ';
        temp = temp->next;
    }
}

void print_backward(Node * tail){
    Node * temp = tail;
    while(temp != NULL){
        cout << temp->val << ' ';
        temp = temp->prev;
    }
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;
    input_list(head,tail);
    delete_at_any_pos(head,2);
    print_forward(head);
    cout << endl;
    print_backward(tail);
    return 0;

}

