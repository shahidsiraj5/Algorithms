#include<bits/stdc++.h>
using namespace std;

void closest(int arr[], int x, int k, int n){
    priority_queue< pair<int, int> > q;
    
    for(int i=0; i<n; i++){
        q.push(make_pair(abs(arr[i] - x), arr[i]));
        if(q.size()>k){
            q.pop();
        }
    }

    while(q.empty() == false){
        cout<<q.top().second<<endl;
        q.pop();
    }
}

int main(){
    int arr[] = {10, 2, 14, 4, 7, 6};
    int x = 5;
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    closest(arr, x, k, n);
    return 1;
}