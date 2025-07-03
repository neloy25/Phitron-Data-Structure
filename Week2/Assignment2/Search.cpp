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

int main()
{
    int t;
    cin >> t;
    while(t--){
        Node * head = NULL; Node * tail = NULL;
        input_list(head,tail);
        int x; cin >> x;

        int idx = 0;
        bool flag = 0;
        while(head != NULL){
            if(head->val == x){
                flag = true;
                break;
            }
            idx++;
            head = head->next;
        }
        if(flag) cout << idx << endl;
        else cout << -1 << endl;
    }
    return 0;
}

