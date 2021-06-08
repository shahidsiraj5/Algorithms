#include<bits/stdc++.h>
using namespace std;

bool isValid(map<char,int> mp){
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second != 0){
            return false;
        }
    }
    return true;
}

string solve(string a, string b, int n, int m){
    map<char,int> mp;
    for(int i=0; i<m; i++){
        mp[b[i]]++;
    }
    int count = mp.size();
    int i=0;
    int j=0;
    int ans = INT_MAX;
    int start = 0;
    while(j<n){
        mp[a[j]]--;
        if(mp[a[j]]==0){
            count--;
        }
        if(count == 0){ 
            while(count==0){
                if(ans > j-i+1){
                    ans = j-i+1;
                    start = i;
                }
                mp[a[i]]++;
                if(mp[a[i]]>0){
                    count++;
                }
                i++;
            }
        }
        j++;
    }

    if(ans!=INT_MAX){
        return a.substr(start, ans);
    }
    return "-1";
}

int main(){
    string a = "geeksforgeeks";
    string b = "ork";
    int n = a.length();
    int m = b.length();
    cout<<solve(a,b,n,m)<<endl;
    return 1;
}