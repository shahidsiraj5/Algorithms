#include<bits/stdc++.h>
using namespace std;

void solve(int lp, int rp, string op){
    if(lp==0 && rp==0){
        cout<<op<<endl;
        return;
    }
    if(lp!=0){
        cout<<"Inside lp: "<<lp<<" "<<rp<<endl;
        cout<<"output is: "<<op<<endl;
        string op1 = op;
        op1.push_back('(');
        solve(lp-1, rp, op1);
    }
    if(rp>lp){
        cout<<"Inside rp: "<<lp<<" "<<rp<<endl;
        cout<<"output is: "<<op<<endl;
        string op1 = op;
        op1.push_back(')');
        rp = rp-1;
        solve(lp, rp-1, op1);
    }
    return;
}

int main(){
    int n=2;
    solve(n, n, "");
    return 1;
}