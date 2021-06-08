#include<bits/stdc++.h>
using namespace std;

vector<int> negativeList(int arr[], int n, int k){
    int i=0;
    int j=0;
    list<int> ls;
    vector<int> ans;
    while(j<n){
        if(arr[j]<0){
            ls.push_back(arr[j]);
        }

        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){
            if(ls.size()==0){
                ans.push_back(0);
            }else{
                ans.push_back(ls.front());
            }

            if(arr[i]>0){
                i++;
            }else if(arr[i]<0){
                ls.pop_front();
                i++;
            }
            j++;
        }
    }

    return ans;
}

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;
    vector<int> v;
    v = negativeList(arr, n, k);
    for(auto i=v.begin(); i!=v.end(); i++){
        cout<<*i<<" ";
    }
    return 1;
}