#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op){
    if(ip.length()==0){
        cout<<op<<endl;
        return;
    }

    if(isalpha(ip[0])){
        string op1 = op;
        string op2 = op;
        op1.push_back(ip[0]);
        op2.push_back(toupper(ip[0]));
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);
    }else{
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip, op1);
    }
    return;
}

int main(){
    string s = "a1b2";
    solve(s, "");
    return 1;
}