#include<bits/stdc++.h>
using namespace std;

int findNum(int arr[], int n, int k){
    priority_queue <int> q;
    for(int i=0; i<n; i++){
        q.push(arr[i]);
        if(q.size() > k){
            q.pop();
        }
    }
    return q.top();
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    cout<<findNum(arr, n, k);
    return 1;
}