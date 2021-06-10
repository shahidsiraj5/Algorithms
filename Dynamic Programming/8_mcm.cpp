#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++){
        int left = solve(arr, i, k);
        int right = solve(arr, k+1, j);
        int temp = left + right + arr[i-1]*arr[k]*arr[j];

        ans = min(ans, temp);
    }

    return ans;
}

int main(){
    int arr[] = {10, 30, 5, 60};
    int n = sizeof(arr)/sizeof(int);
    cout<<solve(arr, 1, n-1);
    return 1;
}