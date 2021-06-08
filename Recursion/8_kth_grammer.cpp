#include<bits/stdc++.h>
using namespace std;

bool grammer(int n, int k){
    if(n==1){
        return false;
    }
    if(k==1){
        return false;
    }

    int mid = (pow(2,n)-1)/2;
    if(k<=mid){
        return grammer(n-1, k);
    }else{
        return !(grammer(n-1, k-mid));
    }
}

int main(){
    int n = 4;
    int k = 6;
    cout<<grammer(n, k);
    return 1;
}