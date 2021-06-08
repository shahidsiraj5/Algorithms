#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

struct node* newnode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int calculate(struct node* root, int &ans){
    if(root==NULL){
        return 0;
    }

    int la = calculate(root->left, ans);
    int ra = calculate(root->right, ans);

    int temp = 1 + max(la,ra);

    ans = max(ans, max(temp,1+la+ra));

    return temp;
}

int diameter(struct node* root){
    if(root==NULL){
        return 0;
    }
    int ans = INT_MIN;
    calculate(root, ans);
    return ans;
}

int main(){
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    cout<<diameter(root);
    return 1;
}