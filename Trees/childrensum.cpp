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

bool isCsum(node*root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    int sum=0;
    if(root->left!=NULL){
        sum+=root->left->data;
    }
    if(root->right!=NULL){
        sum+=root->right->data;
    }
    return (root->data==sum && isCsum(root->left) && isCsum(root->right));
}

int main(){
    node *root=new node(20);
    root->left=new node(8);
    root->right=new node(12);
    root->left->left=new node(3);
    root->left->right=new node(5);
    if(isCsum(root)==true){
        cout<<"Yes!";
    }
    else{
        cout<<"No!";
    }
    return 0;
}