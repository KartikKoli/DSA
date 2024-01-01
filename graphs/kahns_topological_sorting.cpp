//bfs based
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addedge(vector<int> adj[],int u,int v,int indegree[]){
    adj[u].push_back(v);
    indegree[v]++;
}

void topo(vector<int> adj[],int indegree[],int v){
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u]){
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }
}

int main(){
    vector<int> adj[5];
    int indegree[5];
    for(int i=0;i<5;i++){
        indegree[i]=0;
    }
    addedge(adj,0,2,indegree);
    addedge(adj,0,3,indegree);
    addedge(adj,2,3,indegree);
    addedge(adj,1,3,indegree);
    addedge(adj,1,4,indegree);
    topo(adj,indegree,5);
    return 0;
}