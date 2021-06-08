#include<bits/stdc++.h>
using namespace std;

void solve(int n, int one, int zero, string op){
    if(n==0){
        cout<<op<<endl;
        return;
    }

    if(n!=0){
        string op1 = op;
        op1.push_back('1');
        solve(n-1, one+1, zero, op1);
    }

    if(zero+1<=one){
        string op1 = op;
        op1.push_back('0');
        solve(n-1, one, zero+1, op1);
    }
    return;
}

int main(){
    int n = 3;
    solve(n, 0, 0, "");
    return 1;
}