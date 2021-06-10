#include<bits/stdc++.h>
using namespace std;

int solve(int x[], int y[], int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    if(x[n-1] == y[m-1]){
        return 1 + solve(x,y,n-1,m-1);
    }

    return max(solve(x,y,n-1,m), solve(x,y,n,m-1));
}

int main(){
    int a[] = {12, 11, 40, 5, 3, 1};
    int n = sizeof(a)/sizeof(int);
    int b[n];
    for(int i=0; i<n; i++){
        b[i] = a[i];
    }
    sort(b, b+n);
    cout<<solve(a,b,n,n);
    sort(b, b+n, greater<int>());
    cout<<solve(a,b,n,n);
    return 1;
}