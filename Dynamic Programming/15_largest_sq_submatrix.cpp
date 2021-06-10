#include<bits/stdc++.h>
using namespace std;

#define M 8
#define N 6

int solve(int mat[M][N], int m, int n, int &ans){

    if(m==0 || n==0){
        return 0;
    }
    if(m==1 && n==1){
        if(mat[m-1][n-1]==0){
            return 0;
        }else{
            return 1;
        }
    }

    int top = solve(mat, m, n-1, ans);
    int left = solve(mat, m-1, n, ans);
    int topleft = solve(mat, m-1, n-1, ans);

    int size=0;

    if(mat[m-1][n-1] == 1){
        size = 1 + min(min(left, top), topleft);
        ans = max(ans, size);
    }

    return size;
}

int main(){
    int mat[M][N] =
    {
        { 0, 0, 1, 0, 1, 1 },
        { 0, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1 }
    };
    int size = 0;
    solve(mat, M, N, size);
    cout<<size;
    return 1;
}