#include<bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &s, int mid){
    if(s.size()==mid){
        s.pop();
        return;
    }

    int x = s.top();
    s.pop();
    deleteMid(s, mid);
    s.push(x);
}

void printStack(stack<int> &s){
    if(s.size()==0){
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
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int mid = ceil(s.size()/2)+1;

    deleteMid(s, mid);

    printStack(s);

    return 1;
}