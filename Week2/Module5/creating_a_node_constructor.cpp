#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    Node a{10},b{20},c{30};

    a.next = &b;
    b.next = &c;

    cout << a.val << " " << b.val << " " << c.val << endl;
    cout << a.next->val << " " << b.next->val << endl;
    cout << a.next->next->val;
    return 0;

}

