// Problem link: https://www.spoj.com/problems/AGGRCOW/
// Faadu question on binary search

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int mid, int c, int n){
	int cow = 1;
	int j = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]-j >= mid){
            j = arr[i];
            cow++;
        }
        if(cow == c){
            return true;
        }
    }
    return false;
}
int findMin(int arr[], int n, int c){
	sort(arr, arr+n);
	int start = arr[0];
	int end = arr[n-1];
	int mid;
	int res = -1;
	while(start<=end){
		mid = start + (end-start)/2;
		if(isPossible(arr, mid, c, n)){
			res = mid;
			start = mid+1;
		}else{
			end = mid - 1;
		}
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int ans = findMin(arr, n, c);
        cout<<endl<<ans;
	}
	return 0;
}
