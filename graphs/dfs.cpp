#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsrec(vector<int> adj[],int s,bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(int i:adj[s]){
        if(visited[i]==false){
            dfsrec(adj,i,visited);
        }
    }
}

void dfs(vector<int> adj[],int s,int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    dfsrec(adj,0,visited);
}

int main(){
    vector<int> adj[5];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,2,4);
    addedge(adj,3,4);
    dfs(adj,0,5);
    return 0;
}