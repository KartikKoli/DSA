#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node* right;
        node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

int getsize(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+getsize(root->left)+getsize(root->right);
}

int main(){
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    root->right->right=new node(70);
    root->right->right->right=new node(80);
    cout<<"Size: "<<getsize(root);
    return 0;
}