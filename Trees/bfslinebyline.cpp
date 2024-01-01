#include<iostream>
#include<queue>
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

void bfslinebyline(node *root){
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        node *curr=q.front();
        q.pop();
        if(curr==NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

int main(){
    node *root=new node(10);
    root->left=new node(20);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    root->right->right=new node(70);
    root->right->right->right=new node(80);
    bfslinebyline(root);
    return 0;
}