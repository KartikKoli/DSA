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

void bfs(node *root){
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        node *curr=q.front();
        q.pop();
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
    bfs(root);
    return 0;
}