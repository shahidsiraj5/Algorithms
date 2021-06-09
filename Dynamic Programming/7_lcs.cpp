#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int dp[MAX][MAX];

string recursion(string x, string y, int n, int m){
    if(n==0 || m==0){
        return "";
    }

    if(x[n-1] == y[m-1]){
        string str = recursion(x,y,n-1,m-1);
        str.push_back(x[n-1]);
        return str;
    }

    if(dp[n-1][m] > dp[n][m-1]){
        return recursion(x,y,n-1,m);
    }else{
        return recursion(x,y,n,m-1);
    }
}

vector<string> allLcs(string x, string y, int n, int m){
    if(n==0 || m==0){
        vector<string> v;
        v.push_back("");
        return v;
    }

    if(x[n-1] == y[m-1]){
        vector<string> v = allLcs(x,y,n-1,m-1);
        for(int i=0; i<v.size(); i++){
            v[i].push_back(x[n-1]);
        }
        return v;
    }

    if(dp[n-1][m] > dp[n][m-1]){
        return allLcs(x,y,n-1,m);
    }
    if(dp[n][m-1] > dp[n-1][m]){
        return allLcs(x,y,n,m-1);
    }

    vector<string> top = allLcs(x,y,n-1,m);
    vector<string> left = allLcs(x,y,n,m-1);
    top.insert(top.end(), left.begin(), left.end());
    return top;
}

int solve(string x, string y, int n, int m){
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

    // cout<<recursion(x, y, n, m)<<endl;
    vector<string> v = allLcs(x,y,n,m);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    return dp[n][m];
}

int main(){
    string x = "ABCBDAB";
    string y = "BDCABA";

    int n = x.length();
    int m = y.length();

    cout<<solve(x,y,n,m)<<endl;
    return 1;
}