#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n){
    int start = 0;
    int end = n-1;
    int mid;
    int index = -1;
    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
            index = mid;
        }
        if(arr[start]<arr[mid]){
            start = mid+1;
        }else if(arr[mid]<arr[end]){
            end = mid-1;
        }
    }
    return index;
}

int main(){
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n =sizeof(arr)/sizeof(int);
    cout<<solve(arr, n);
    return 1;
}