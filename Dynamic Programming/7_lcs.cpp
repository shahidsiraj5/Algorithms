#include<bits/stdc++.h>
using namespace std;

int solve(string x, string y, int n, int m){
    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<=m; i++){
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i=n;
    int j=m;
    vector<char> v;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            v.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(v.begin(), v.end());
    for(auto i=v.begin(); i!=v.end(); i++){
        cout<<*i;
    }

    cout<<endl;
    return dp[n][m];
}

int main(){
    string x = "AGGTAB";
    string y = "GXTXAYB";

    int n = x.length();
    int m = y.length();

    cout<<solve(x,y,n,m)<<endl;
    return 1;
}