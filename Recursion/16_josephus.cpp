#include<bits/stdc++.h>
using namespace std;

void recursion(vector<int> &v, int index, int k){
    if(v.size()==1){
        cout<<v[0]<<endl;
        return;
    }

    index = (index + k)%(v.size());
    v.erase(v.begin()+index);
    recursion(v, index, k);
    return;
}

int solution(int n, int k){
    if(n==1){
        return 1;
    }

    int sol = solution(n-1,k) + k;
    if(sol<=n){
        return sol;
    }
    return sol%n;
}

int main(){
    int n = 14;
    int k = 2;
    vector<int> v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    recursion(v, 0, k-1);
    cout<<endl;
    cout<<solution(n, k);
    return 1;
}