#include<iostream>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}

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

int getmax(node *root){
    if(root==NULL) return INT8_MIN;
    return max(root->data,max(getmax(root->left),getmax(root->right)));
}

int main(){
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(100);
    root->right=new node(30);
    root->right->right=new node(70);
    root->right->right->right=new node(80);
    cout<<"Max: "<<getmax(root);
    return 0;
}