#include<bits/stdc++.h>
using namespace std;

int solve(int f, int e){
    if(f==0 || f==1){
        return f;
    }
    if(e==1){
        return f;
    }
    int ans = INT_MAX;
    for(int k=1; k<=f; k++){
        int br = solve(k-1, e-1);
        int nbr = solve(f-k, e);
        int temp = 1 + max(br, nbr);
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    int f = 4;
    int e = 2;
    cout<<solve(f,e)<<endl;
    return 1;
}