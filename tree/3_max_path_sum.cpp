#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
};
 
struct Node* newNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return (newNode);
}

int solve(struct Node* root, int &ans){
    if(root==NULL){
        return 0;
    }

    int la = solve(root->left, ans);
    int ra = solve(root->right, ans);

    int temp = max(root->data + max(la,ra), root->data);

    ans = max(ans, max(temp, root->data+la+ra));

    return temp;
}

int findMaxSum(struct Node* root){
    if(root==NULL){
        return 0;
    }
    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}

int main(){
    struct Node *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    cout<<findMaxSum(root);
    return 0;
}