#include<bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n){
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0; i<n; i++){
        q.push(arr[i]);
    }
    int total_cost = 0;
    while(q.size()!=1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        int cost = a + b;
        q.push(cost);
        total_cost = total_cost + cost;
    }
    return total_cost;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    cout<<minCost(arr, n);
    return 1;
}