#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for(int i=1; i<=sum; i++){
        dp[0][i] = false;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    int mn = INT_MAX;

    for(int i=0; i<=sum; i++){
        if(dp[n][i] == true){
            mn = min(mn, abs(sum - 2*i));
        }
    }

    return mn;
}

int main(){
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(int);
    int sum = 23;
    cout<<solve(arr, n, sum);
    return 1;
}