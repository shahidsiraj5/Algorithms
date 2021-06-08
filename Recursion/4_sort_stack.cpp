#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.size() == 0){
        s.push(temp);
        return;
    }
    if(temp> s.top()){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sortStack(stack<int> &s){
    if(s.size() == 1){
        return;
    }

    int temp = s.top();
    s.pop();
    sortStack(s);
    insert(s, temp);
}

void printStack(stack<int> s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);
}

int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    sortStack(s);

    printStack(s);
    
    return 1;
}
