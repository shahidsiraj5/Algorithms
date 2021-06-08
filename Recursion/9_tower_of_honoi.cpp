#include<bits/stdc++.h>
using namespace std;

void solve(int n, string source, string aux, string dest){
    if(n==1){
        cout<<"Put "<<n<<" from "<<source<<" to "<<dest<<endl;
        return;
    }
    solve(n-1, source, dest, aux);
    cout<<"Put "<<n<<" from "<<source<<" to "<<dest<<endl;
    solve(n-1, aux, source ,dest);
}

int main(){
    int n = 3;
    solve(n, "source", "aux", "des");
    return 1;
}