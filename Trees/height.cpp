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

int max(int a, int b){
    return (a>b)?a:b;
}

int height(node *root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

int main(){
    node *root=new node(30);
    root->left=new node(40);
    root->left->left=new node(70);
    root->right=new node(50);
    root->right->left=new node(60);
    root->right->right=new node(80);
    cout<<height(root);
    return 0;
}