#include<bits/stdc++.h>
using namespace std;

void print(int n){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    print(n-1);
    cout<<n<<endl;
}


int main(){
    int n = 7;
    print(n);
    return 1;
}