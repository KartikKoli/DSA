#include<iostream>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[],int s,bool visited[]){
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x: adj[u]){
            if(visited[x]==false){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}

void bfsup(vector<int> adj[],int v){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            bfs(adj,i,visited);
        }
    }
}

int main(){
    vector<int> adj[7];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,4,5);
    addedge(adj,4,6);
    addedge(adj,5,6);
    bfsup(adj,7);
    return 0;
}