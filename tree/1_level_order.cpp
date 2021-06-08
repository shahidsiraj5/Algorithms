#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node *right;
};

struct node* newnode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int height(struct node* root){
    if(root==NULL){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void traverse(struct node* root, int h){
    if(h==1){
        cout<<root->data<<" ";
        return;
    }

    traverse(root->left, h-1);
    traverse(root->right, h-1);
}

void levelorder(struct node* root){
    if(root==NULL){
        return;
    }

    int h = height(root);
    for(int i=1; i<=h; i++){
        traverse(root, i);
    }
}

void levelOrder2(struct node* root){
    if(root==NULL){
        return;
    }
    queue<struct node* > q;
    q.push(root);
    while(q.empty() == false){
        struct node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        } 
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

void traverserev(struct node* root, int h){
    if(h==1){
        cout<<root->data<<" ";
        return;
    }
    traverserev(root->right, h-1);
    traverserev(root->left, h-1);
}

void zigzag(struct node* root){
    if(root==NULL){
        return;
    }
    int h = height(root);
    for(int i=1; i<=h; i++){
        if(i%2 == 0){
            traverserev(root, i);
        }else if(i%2 != 0){
            traverse(root, i);
        }
    }
}

int main(){
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(7);
    root->left->right = newnode(6);
    root->right->left = newnode(5);
    root->right->right = newnode(4);

    // int h = height(root)<<endl;
    // inorder(root);
    // cout<<endl;
    // levelorder(root);
    // cout<<endl;
    // levelOrder2(root);
    zigzag(root);
    return 1;
}