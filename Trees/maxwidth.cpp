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

int max(int a,int b){
    return (a>b)?a:b;
}

int maxwidth(node* root){
    if(root==NULL) return 0;
    queue<node*> q;
    q.push(root);
    int count;
    int res=0;
    while(q.empty()==false){
        count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++){
            node* curr=q.front();
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
    return res;
}

int main(){
    node* root=new node(8);
    root->left=new node(30);
    root->right=new node(20);
    root->left->left=new node(90);
    root->left->right=new node(100);
    root->right->left=new node(70);
    root->right->right=new node(300);
    cout<<maxwidth(root);
    return 0;
}