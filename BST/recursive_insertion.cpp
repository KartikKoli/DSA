#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left=NULL;
        node* right=NULL;
        node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

node* insert(node* root,int val){
    if(root==NULL) return new node(val);
    else if(val<root->data) root->left=insert(root->left,val);
    else if(val>root->data) root->right=insert(root->right,val);
    return root;
}

int main(){
    node* root=new node(15);
    root->left=new node(5);
    root->right=new node(20);
    root->left->left=new node(3);
    root->right->left=new node(18);
    root->right->right=new node(80);
    root->right->left->left=new node(16);
    cout<<insert(root,7);
    return 0;
}