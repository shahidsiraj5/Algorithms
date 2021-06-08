#include<bits/stdc++.h>
using namespace std;

int memo[10][100];

int solve(int wt[], int val[], int W, int n){
    if(n==0){
        return 0;
    }
    if(W==0){
        return 0;
    }

    if(memo[n][W]!=-1){
        return memo[n][W];
    }

    if(wt[n-1]>W){
        return memo[n][W] = solve(wt, val, W, n-1);
    }else{
        return memo[n][W] = max(solve(wt, val, W, n-1), val[n-1]+solve(wt, val, W-wt[n-1], n-1));
    }
}

int solvedp(int wt[], int val[], int W, int n){
    int dp[n+1][W+1];

    for(int i=0; i<=W; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }

    return dp[n][W];
}

int main(){
    memset(memo, -1, sizeof(memo));
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout<<solve(wt, val, W, n)<<endl; //using memoization
    cout<<solvedp(wt, val, W, n); //using top-down
    return 1;
}
