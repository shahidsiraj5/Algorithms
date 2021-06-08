#include<bits/stdc++.h>
using namespace std;

int maxSubarray(int arr[], int n, int k){
    int i=0;
    int j=0;
    int res = INT_MIN;
    int sum = 0;
    while(j<n){
        sum = sum+arr[j];
        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){
            res = max(res, sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }
    return res;
}

int main(){
    int arr[] = {2,5,1,8,2,9,1};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    cout<<maxSubarray(arr, n, k);
    return 1;
}