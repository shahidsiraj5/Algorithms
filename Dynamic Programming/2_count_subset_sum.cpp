#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int sum, int n){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }

    if(arr[n-1]>sum){
        return solve(arr, sum, n-1);
    }
    return solve(arr, sum, n-1) + solve(arr, sum-arr[n-1], n-1);
}

int main(){
    int arr[] = {1, 2, 3, 3};
    int sum = 6;
    int n = sizeof(arr)/sizeof(int);
    cout<<solve(arr, sum, n);
    return 1;
}