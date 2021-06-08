#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void verticalSumUtil(struct Node* root, int origin, map<int,int> &mp){
    if(root==NULL){
        return;
    }
    mp[origin] = mp[origin]+root->data;
    verticalSumUtil(root->left, origin-1, mp);
    verticalSumUtil(root->right, origin+1, mp);
}

void verticalSum(struct Node* root){
    map<int,int> mp;
    int origin = 0;
    verticalSumUtil(root, origin, mp);
    for(auto i=mp.begin(); i!=mp.end(); i++){
        cout<<i->first<<" : "<<i->second<<endl;
    }
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    verticalSum(root);
    return 1;
}