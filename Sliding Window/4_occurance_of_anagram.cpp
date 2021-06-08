#include<bits/stdc++.h>
using namespace std;

// int countOccurance(string a, string b, int n, int k){
//     int obj = 0;
//     for(int i=0; i<b.length(); i++){
//         obj = obj^b[i];
//     }
//     int i=0;
//     int j=0;
//     int xorr = 0;
//     int occurance = 0;
//     while(j<n){
//         xorr = xorr^a[i];
//         if(j-i+1 < k){
//             j++;
//         }else if(j-i+1 == k){
//             if(xorr^obj == 0){
//                 occurance++;
//             }
//             xorr = xorr^a[i];
//             i++;
//             j++;
//         }
//     }

//     return occurance;
// }

bool isAnagram(map<char, int> mp){
    for(auto i=mp.begin(); i!=mp.end(); i++){
        if(i->second !=0){
            return false;
        }
    }
    return true;
}

int countOccurance(string a, string b, int n, int k){
    map<char, int> mp;
    for(int i=0; i<b.length(); i++){
        mp[b[i]]++;
    }
    int i=0;
    int j=0;
    int occurance = 0;
    while(j<n){
        mp[a[j]]--;
        if(j-i+1 < k){
            j++;
        }else if (j-i+1 == k){
            if(isAnagram(mp)){
                occurance++;
            }
            mp[a[i]]++;
            i++;
            j++;
        }
    }
    return occurance;
}

int main(){
    string a = "forxxorfxdofr";
    string b = "for";

    int n = a.length();
    int k = b.length();

    cout<<countOccurance(a, b, n, k)<<endl;
    return 1;
}