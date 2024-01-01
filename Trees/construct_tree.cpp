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

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int preindex=0;

node* ctree(int in[],int pre[],int start,int end){
    if(start>end) return NULL;
    node* root=new node(pre[preindex++]);

    int inindex;
    for(int i=start;i<=end;i++){
        if(root->data==in[i]){
            inindex=i;
            break;
        }
    }
    root->left=ctree(in,pre,start,inindex-1);
    root->right=ctree(in,pre,inindex+1,end);
    return root;
}

int main(){
    int in[5]={20,10,40,30,50};
    int pre[5]={10,20,30,40,50};
    node* root=ctree(in,pre,0,4);
    inorder(root);
    return 0;
}