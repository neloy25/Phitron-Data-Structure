#include<bits/stdc++.h>
using namespace std;

int y = 100;
void fun(int* &p){
    p = &y;
}

int main()
{
    int x = 10;
    int *p = &x;
    fun(p);
    cout << "main: " << *p << endl;
    return 0;
}

