#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
        node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

void printknode(node *root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }
    else{
        printknode(root->left,k-1);
        printknode(root->right,k-1);
    }
}

int main(){
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    root->right->right=new node(70);
    root->right->right->right=new node(80);
    printknode(root,2);
    return 0;
}