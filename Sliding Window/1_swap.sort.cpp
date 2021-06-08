#include<bits/stdc++.h>
using namespace std;

void swapsort(int arr[], int n){
    int i=0;
    while(i<n){
        if(arr[i] == arr[arr[i]-1]){
            i++;
        }else{
            swap(arr[i], arr[arr[i]-1]);
        }
    }
}

int main(){
    int arr[] = {2,3,1,8,2,3,5,1};
    int n = sizeof(arr)/sizeof(int);

    swapsort(arr, n);
    
    set<int> duplicate;
    set<int> missing;
    for(int i=0; i<n; i++){
        if(arr[i] != i+1){
            duplicate.insert(arr[i]);
            missing.insert(i+1);
        }
    }

    for(auto i=duplicate.begin(); i!=duplicate.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i=missing.begin(); i!=missing.end(); i++){
        cout<<*i<<" ";
    }

    return 1;
}