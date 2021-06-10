#include<bits/stdc++.h>
using namespace std;

int solve(string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    if(x[n-1] == y[m-1]){
        return 1 + solve(x,y,n-1,m-1);
    }

    return max(solve(x,y,n-1,m), solve(x,y,n,m-1));
}

int main(){
    string x = "ABBDCACB";
    int n = x.length();
    string y = x;
    reverse(y.begin(), y.end());
    cout<<solve(x,y,n,n)<<endl;
    return 1;
}