#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j){
    if(isPalindrome(s,i,j) || i>=j){
        return 0;
    }

    int k;
    int ans = INT_MAX;
    for(k=i; k<j; k++){
        int temp = 1+solve(s,i,k)+solve(s, k+1, j);
        ans = min(temp, ans);
    }
    return ans;
}

int main(){
    string str = "ababbbabbababa";
    int len = str.length();
    cout<<solve(str, 0, len-1);
    return 1;
}