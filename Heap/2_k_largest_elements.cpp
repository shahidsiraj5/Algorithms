#include<bits/stdc++.h>
using namespace std;

void findNum(int arr[], int k, int n){
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=0; i<n; i++){
        q.push(arr[i]);
        if(q.size() > k){
            q.pop();
        }
    }

    while(q.empty() == false){
        cout<<q.top()<<endl;
        q.pop();
    }
}

int main(){
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;
    int n = sizeof(arr)/sizeof(int);
    findNum(arr, k , n);
    return 1;
}