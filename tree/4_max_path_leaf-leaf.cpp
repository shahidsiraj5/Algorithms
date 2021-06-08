#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node = new(struct Node);
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int solve(struct Node* root, int &ans){
    if(root==NULL){
        return 0;
    }

    int la = solve(root->left, ans);
    int ra = solve(root->right, ans);

    int temp = root->data + max(la, ra);

    ans = max(ans, root->data+la+ra);

    return temp;
}

int maxPathSum(struct Node* root){
    if(root==NULL){
        return 0;
    }

    int ans = INT_MIN;
    solve(root, ans);
    return ans;
}

int main(){
    struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);
    cout << "Max pathSum of the given binary tree is "
         << maxPathSum(root);
    return 0;
}