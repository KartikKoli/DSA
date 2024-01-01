#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

int max(int a,int b){
    return (a>b)?a:b;
}

int isbalanced(node* root){
    if(root==NULL) return 0;
    int lh=isbalanced(root->left);
    if(lh==-1) return -1;
    int rh=isbalanced(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    else{
        return max(lh,rh)+1;
    }
}

int main(){
    node *root=new node(10);
    root->left=new node(5);
    root->right=new node(30);
    root->right->left=new node(15);
    root->right->right=new node(20);
    if(isbalanced(root)!=-1){
        cout<<"YES!";
    }
    else{
        cout<<"NO!";
    }
    return 0;
}