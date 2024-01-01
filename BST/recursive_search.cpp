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

bool search(node* root,int key){
    if(root==NULL) return false;
    else if(root->data==key) return true;
    else if(key<root->data) return search(root->left,key);
    else return search(root->right,key);
}

int main(){
    node* root=new node(15);
    root->left=new node(5);
    root->right=new node(20);
    root->left->left=new node(3);
    root->right->left=new node(18);
    root->right->right=new node(80);
    root->right->left->left=new node(16);
    bool result=search(root,80);
    if(result) cout<<"Found!";
    else cout<<"Not found!";
    return 0;
}