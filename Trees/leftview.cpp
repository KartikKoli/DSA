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

int maxlevel=0;
void printleft(node *root,int level){
    if(root==NULL) return;
    if(maxlevel<level){
        cout<<root->data<<endl;
        maxlevel=level;
    }
    printleft(root->left,level+1);
    printleft(root->right,level+1);
}

int main(){
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    root->right->right=new node(70);
    root->right->right->right=new node(80);
    printleft(root,1);
    return 0;
}