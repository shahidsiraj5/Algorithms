#include<bits/stdc++.h>
using namespace std;

vector<int> maxSub(int arr[], int n, int k){
    int i=0; 
    int j=0;
    list<int> ll;
    priority_queue<int> qu;
    vector<int> ans;
    while(j<n){
        ll.push_back(arr[j]);
        if(qu.empty()==true){
            qu.push(arr[j]);
        }else{
            if(arr[j] > qu.top()){
                qu.pop();
                qu.push(arr[j]);
            }
        }
        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){
            ans.push_back(qu.top());
            if(ll.front() == qu.top()){
                qu.pop();
            }
            ll.pop_front();
            i++;
            j++;
        }
    }

    return ans;
}

int main(){
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    vector<int> v;
    v = maxSub(arr, n, k);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 1;
}