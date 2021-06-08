#include<bits/stdc++.h>
using namespace std;

int largestSubarr(int arr[], int n, int sum){
    int i=0;
    int j=0;
    int curr=0;
    int ans = INT_MIN;
    while(j<n){
        curr = curr + arr[j];
        if(curr<sum){
            j++;
        }else if(curr == sum){
            ans = max(ans, j-i+1);
            j++;
        }else{
            while(curr > sum){
                curr = curr - arr[i];
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {4,1,1,1,2,3,5};
    int n = sizeof(arr)/sizeof(n);
    int sum = 5;
    cout<<largestSubarr(arr, n, sum);
    return 1;
}