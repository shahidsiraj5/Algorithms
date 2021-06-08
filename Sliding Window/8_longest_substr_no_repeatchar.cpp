#include<bits/stdc++.h>
using namespace std;

bool isValid(map<char,int> mp){
    for(auto i=mp.begin(); i!=mp.end(); i++){
        if(i->second > 1){
            return false;
        }
    }
    return true;
}

int lenSub(string s, int n){
    int i=0;
    int j=0;
    int ans = INT_MIN;
    map<char,int> mp;
    while(j<n){
        mp[s[j]]++;
        if(isValid(mp)){
            ans = max(ans, j-i+1);
            j++;
        }else{
            while(isValid(mp)==false){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
    }
    return ans;
}

int main(){
    string s = "pwwkew";
    int n = s.length();
    cout<<lenSub(s, n);
    return 1;
}