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

node* getsuccessor(node*root){
    node* curr=root->right;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

node* del(node*root,int x){
    if(root==NULL) return root;
    if(x<root->data) root->left=del(root->left,x);
    else if(x>root->data) root->right=del(root->right,x);
    else{
        if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else{
            node* successor=getsuccessor(root);
            root->data=successor->data;
            root->right=del(root->right,successor->data);
        }
        return root;
    }
}

int main(){
    node* root=new node(15);
    root->left=new node(5);
    root->right=new node(20);
    root->left->left=new node(3);
    root->right->left=new node(18);
    root->right->right=new node(80);
    root->right->left->left=new node(16);
    return 0;
}