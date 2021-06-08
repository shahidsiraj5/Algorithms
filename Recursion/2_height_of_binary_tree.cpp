#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left, *right;
};

int height(struct node* root){
    if(root==NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return 1+max(lh, rh);
}

struct node* newnode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(){
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    cout<<height(root);
    return 1;
}