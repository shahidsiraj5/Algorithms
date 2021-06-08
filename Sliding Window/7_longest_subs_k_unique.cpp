#include<bits/stdc++.h>
using namespace std;

int longestSubs(string s, int n, int k){
    int i=0;
    int j=0;
    map<char, int> mp;
    int ans = INT_MIN;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()<3){
            j++;
        }else if(mp.size()== 3){
            ans = max(ans, j-i+1);
            j++;
        }else {
            while(mp.size() > 3){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }

    return ans;
}

int main(){
    string s = "aabacbebebe";
    int k = 3;
    int n = s.length();
    cout<<longestSubs(s, n, k);
    return 1;
}