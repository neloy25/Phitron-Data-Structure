#include <iostream>
using namespace std;

class myStack {
    class Node {
    public:
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = NULL;
        }
    };

    Node* topNode = NULL;
    int len = 0;

public:
    int size() {
        return len;
    }

    bool empty() {
        return topNode == NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
        len++;
    }

    void pop() {
        Node* delNode = topNode;
        topNode = topNode->next;
        delete delNode;
        len--;
    }

    int top() {
        return topNode->val;
    }
};


int main()
{
   myStack st;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st.push(val);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}