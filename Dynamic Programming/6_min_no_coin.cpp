#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<=sum; i++){
        dp[0][i] = INT_MAX-1;
    }
    for(int i=1; i<=sum; i++){
        if(i%arr[0] == 0){
            dp[1][i] = i/arr[0];
        }else{
            dp[1][i] = INT_MAX-1;
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]>sum){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-arr[i-1]]);
            }
        }
    }

    return dp[n][sum];
}

int main(){
    int arr[] = {25, 10, 5};
    int n = 3;
    int sum = 30;
    cout<<solve(arr, n, sum);
    return 1;
}