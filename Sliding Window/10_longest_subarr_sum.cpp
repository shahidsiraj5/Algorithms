#include<bits/stdc++.h>
using namespace std;

int longestSubarr(int arr[], int n, int k){
    int sum = 0;
    map<int,int> mp;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
        if(sum == k){
            ans = max(ans, i+1);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
        if(mp.find(sum-k) != mp.end()){
            ans = max(ans, i-mp[sum-k]);
        }
    }
    return ans;
}

int main(){
    int arr[] = {-5, 8, -14, 2, 4, 12};
    int n = sizeof(arr)/sizeof(int);
    int k = -5;
    cout<<longestSubarr(arr, n, k)<<endl;
    return 1;
}