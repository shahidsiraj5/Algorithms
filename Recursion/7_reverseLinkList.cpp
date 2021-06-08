#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

struct node* newnode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return (node);
}

void printlist(struct node* head){
    struct node* ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

struct node* reverseList(struct node* ptr){
    if(ptr->next==NULL || ptr==NULL){
        return ptr;
    }
    struct node* temp = reverseList(ptr->next);
    ptr->next->next = ptr;
    ptr->next = NULL;

    return temp;
}

int main(){
    struct node *head = newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4);
    struct node* ptr = head;
    struct node* x = reverseList(ptr);
    printlist(x);
    return 1;
}