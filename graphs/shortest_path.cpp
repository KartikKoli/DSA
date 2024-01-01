#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void spath(vector<int> adj[],int s,int v){
    int dist[v]={-1};
    dist[s]=0;
    bool visited[v];
    queue<int>q;
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    visited[s]=true;
    q.push(s);
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        for(int x:adj[u]){
            if(visited[x]==false){
                dist[x]=dist[u]+1;
                visited[x]=true;
                q.push(x);
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<s<<" -> "<<i<<" :"<<dist[i]<<endl;
    }
}

int main(){
    vector<int> adj[4];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,2,3);
    spath(adj,0,4);
    return 0;
}