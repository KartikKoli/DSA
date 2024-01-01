#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node* right;
        node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

void traversal(node *root){
    if(root==NULL) return;
    queue<node*> q;
    stack<int> s;
    q.push(root);
    bool reverse=false;
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
            node *curr=q.front();
            q.pop();
            if(reverse){
                s.push(curr->data);
            }
            else{
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        if(reverse){
            while(s.empty()==false){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<endl;
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
    traversal(root);
    return 0;
}