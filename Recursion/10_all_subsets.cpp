#include<bits/stdc++.h>
using namespace std;

set<string> s;

void powerSet(string ip, string op){
    if(ip.length()==0){
        s.insert(op);
        return;
    }

    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    powerSet(ip, op);
    powerSet(ip, op2);
    return;
}


int main(){
    string str = "abc";
    powerSet(str, "");
    for(auto i=s.begin(); i!=s.end(); i++){
        cout<<*i<<" ";
    }
    return 1;
}