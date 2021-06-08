#include<bits/stdc++.h>
using namespace std;

void printSeq(string ip, string op){
    if(ip.length()==0){
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    op2.insert(op2.end()+0, '_');
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    printSeq(ip, op2);
    printSeq(ip, op1);
    return;
}

int main(){
    string s = "abc";
    string op = "";
    op.push_back(s[0]);
    s.erase(s.begin()+0);
    printSeq(s, op);
    return 1;
}