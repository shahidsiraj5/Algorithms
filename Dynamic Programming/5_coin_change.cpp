#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sum){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }

    if(arr[n-1]>sum){
        return solve(arr, n-1, sum);
    }

    return solve(arr, n-1, sum) + solve(arr, n, sum-arr[n-1]);
}

int main(){
    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    int sum = 4;
    cout<<solve(arr, n, sum);
    return 1;
}