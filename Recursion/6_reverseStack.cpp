#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> &s){
    if(s.size() == 0){
        return;
    }
    int x = s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);
}

void insert(stack<int> &s, int x){
    if(s.size() == 0){
        s.push(x);
        return;
    }
    int a = s.top();
    s.pop();
    insert(s, x);
    s.push(a);
}

void reverseStack(stack<int> &s){
    if(s.size()==0){
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    insert(s, x);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    printStack(s);
    reverseStack(s);
    cout<<endl;
    printStack(s);
    return 1;
}