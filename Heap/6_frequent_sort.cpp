#include<bits/stdc++.h>
using namespace std;

void frSort(int arr[], int n){
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0; i<n; i++){
        q.push(arr[i]);
    }
    
    while(q.empty() == false){
        cout<<q.top()<<endl;
        q.pop();
    }
}

int main(){
    int arr[] = {2, 5, 2, 8, 5, 6, 8, 8};
    int n = sizeof(arr)/sizeof(int);
    frSort(arr, n);
    return 1;
}