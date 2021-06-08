#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int x){
    int start = 0;
    int end = n-1;
    int mid;
    int index=-1;
    while(start<=end){
        mid = start + (end-start)/2;
        if(arr[mid]==x){
            index = mid;
            end = mid-1;
        }else if(arr[mid]>x){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return index;
}

int main(){
    int arr[] = {2,4,10,10,10,18,20};
    int n = sizeof(arr)/sizeof(int);
    cout<<solve(arr,n, 10);
    return 1;
}