#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}

bool dfsrec(vector<int> adj[],int s,bool visited[],bool recst[]){
    visited[s]=true;
    recst[s]=true;
    for(int x:adj[s]){
        if(visited[x]==false && dfsrec(adj,x,visited,recst)){
            return true;
        }
        else if(recst[x]==true) return true;
    }
    recst[s]=false;
    return false; 
}

bool dfs(vector<int> adj[],int v){
    bool visited[v];
    bool recst[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
        recst[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            if(dfsrec(adj,i,visited,recst)==true) return true;
        }
    }
    return false;
}

int main(){
    vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,2,1);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,4,5);
    addedge(adj,5,3);
    bool res=dfs(adj,6);
    if(res==true) cout<<"Cycle detected!";
    else cout<<"Cycle not detected!";
    return 0;
}