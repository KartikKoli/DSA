#include<iostream>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[],int v,int s){
    bool visited[v+1];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u]){
            if(visited[x]==false){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}

int main(){
    vector<int> adj[5];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,3);
    addedge(adj,1,2);
    addedge(adj,2,3);
    addedge(adj,2,4);
    addedge(adj,3,4);
    bfs(adj,5,0);
    return 0;
}