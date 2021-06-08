#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int len[], int n, int total){
    if(total==0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    if(len[n-1] > total){
        return solve(arr, len, n-1, total);
    }
    return max(solve(arr,len,n-1,total), arr[n-1]+solve(arr, len, n, total-len[n-1]));
}

int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(arr)/sizeof(n);
    int len[] = {1,2,3,4,5,6,7,8};
    cout<<solve(arr, len, n, n);
    return 1;
}