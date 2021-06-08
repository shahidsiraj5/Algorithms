#include<bits/stdc++.h>
using namespace std;

void sortArr(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int> > q;
    vector<int> v;
    for(int i=0; i<n; i++){
        q.push(arr[i]);
        if(q.size() > k){
            v.push_back(q.top());
            q.pop();
        }
    }

    while(q.empty() == false){
        v.push_back(q.top());
        q.pop();
    }

    for(int i=0; i<n; i++){
        cout<<v[i]<<endl;
    }
}

int main(){
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int n = sizeof(arr)/sizeof(int);
    sortArr(arr, n, k);
    return 1;
}