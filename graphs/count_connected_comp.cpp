#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsrec(vector<int> adj[],int s,bool visited[]){
    visited[s]=true;
    for(int i:adj[s]){
        if(visited[i]==false){
            dfsrec(adj,i,visited);
        }
    }
}

int count(vector<int> adj[],int v){
    int cn=0;
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            cn++;
            dfsrec(adj,i,visited);
        }
    }
    return cn;
}

int main(){
    vector<int> adj[5];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,3,4);
    int res=count(adj,5);
    cout<<res;
    return 0;
}