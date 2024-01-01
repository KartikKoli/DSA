#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define cap 50
vector<int> revadj[cap];

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}

void rev(vector<int> adj[],int v){
    for(int i=0;i<v;i++){
        for(auto x:adj[i]){
            revadj[x].push_back(i);
        }
    }
}

void dfsrec(vector<int> adj[],int u,bool visited[],stack<int> st,int v){
    visited[u]=true;
    for(auto x:adj[u]){
        if(visited[x]==false){
            visited[x]=true;
            dfsrec(adj,x,visited,st,v);
        }
        st.push(u);
    }
}

vector<int> kosaraju(vector<int> adj[],int v){
    vector<int> res;
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    stack<int> st;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfsrec(adj,i,visited,st,v);
        }
    }
    while(st.empty()==false){
        res.push_back(st.top());
        st.pop();
    }
    rev(adj,v);
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfsrec(adj,i,visited,st,v);
        }
    }
}