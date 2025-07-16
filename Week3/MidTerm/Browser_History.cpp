#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string val;
    Node * next;
    Node* prev;
    
    Node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node * &head, Node * &tail,string val){
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
        string val; cin >> val;
        if(val == "end"){
            break;
        }
        insert_at_tail(head, tail, val);
    }
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;
    input_list(head,tail);
    int q; cin >> q;
    Node * curr = NULL;
    while(q--){
        string task; cin >> task;
        if(task == "visit") {
            string s; cin >> s;
            Node * tmp = head;
            bool flag = false;
            while(tmp != NULL) {
                if(tmp->val == s) {
                    cout << s << endl;
                    curr = tmp;
                    flag = true;
                    break; 
                }
                tmp = tmp->next;
            }
            if(!flag) cout << "Not Available" << endl;
        } else if(task == "prev") {
            if(curr->prev != NULL) {
                curr = curr->prev;
                cout << curr->val << endl;
            } else{
                cout << "Not Available" << endl;
            }
        } else{
            if(curr->next != NULL) {
                curr = curr->next;
                cout << curr->val << endl;
            } else{
                cout << "Not Available" << endl;
            }
        }
    }
    return 0;

}

