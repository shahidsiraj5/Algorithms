#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

void kFrequent(int arr[], int n, int k){
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    priority_queue<pi, vector<pi>, greater<pi> > q;
    for(auto i= mp.begin(); i!=mp.end(); i++){
        q.push(make_pair(i->second, i->first));
        if(q.size() > k){
            q.pop();
        }
    }

    while(q.empty() == false){
        cout<<q.top().second<<endl;
        q.pop();
    }
}

int main(){
    int arr[] = {1,1,1,3,2,2,4};
    int k = 2;
    int n = sizeof(arr)/sizeof(int);
    kFrequent(arr, n, k);
    return 1;
}