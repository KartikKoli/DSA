#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfsrec(vector<int> adj[],int s,bool visited[],int parent){
    visited[s]=true;
    for(int x: adj[s]){
        if(visited[x]==false){
            if(dfsrec(adj,x,visited,s)==true) return true;
        }
        else if(x!=parent) return true;
    }
    return false;
}

bool dfs(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            if(dfsrec(adj,i,visited,-1)==true) return true;
        }
    }
    return false;
}

int main(){
    vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,2,4);
    addedge(adj,4,5);
    bool res=dfs(adj,6);
    if(res==true) cout<<"Cycle detected!";
    else cout<<"Cycle not detected!";
    return 0;
}