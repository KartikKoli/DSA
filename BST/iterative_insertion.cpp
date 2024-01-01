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

node* insert(node* root,int x){
    node* temp=new node(x);
    node* parent;
    node* curr=root;
    while(curr!=NULL){
        parent=curr;
        if(x<curr->data) curr=curr->left;
        else if(x>curr->data) curr=curr->right;
        else return root;
    }
    if(parent==NULL) return temp;
    if(x<parent->data) parent->left=temp;
    else parent->right=temp;
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