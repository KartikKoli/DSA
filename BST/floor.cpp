#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int key){
            data=key;
            left=NULL;
            right=NULL;
        }
};

node* floor(node* root,int x){
    node* res=NULL;
    while(root!=NULL){
        if(root->data>x){
            root=root->left;
        } 
        else if(root->data<x){
            res=root;
            root=root->right;
        } 
        else return root;
    }
    return res;
}