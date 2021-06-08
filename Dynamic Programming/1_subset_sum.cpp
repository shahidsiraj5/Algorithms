//equal sum partition
#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }

    if(arr[n-1] > sum){
        return subsetSum(arr, n-1, sum);
    }
    return subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum);
}

int main(){
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr)/sizeof(int);
    int sum = 9;
    cout<<subsetSum(arr, n, sum);
    return 1;
}