#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

void addedge(vector<pair<int,int>> adj[],int u,int v,int w,int indegree[]){
    adj[u].push_back(make_pair(v,w));
    indegree[v]++;
}

vector<int> topo(vector<pair<int,int>> adj[],int indegree[],int v){
    vector<int> result;
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(q.empty()==false){
        int u=q.front();
        result.push_back(u);
        q.pop();
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            indegree[it->first]--;
            if(indegree[it->first]==0) q.push(it->first);
        }
    }
    return result;
}

void mincost(vector<pair<int,int>> adj[],int s,int v,int indegree[]){
    int cost[v];
    for(int i=0;i<v;i++){
        cost[i]=INT_MAX;
    }
    cost[s]=0;
    vector<int> res=topo(adj,indegree,v);
    for(int x:res){
        for(auto it=adj[x].begin();it!=adj[x].end();it++){
            if(cost[it->first]>cost[x]+it->second) cost[it->first]=cost[x]+it->second;
        }   
    }
    for(int i=0;i<v;i++){
        if(cost[i]!=INT_MAX) cout<<"Cost from "<<s<<" to "<<i<<":"<<cost[i]<<endl;
    }
}

int main(){
    int node;
    vector<pair<int,int>> adj[6];
    int indegree[6]={0};
    addedge(adj,0,1,2,indegree);
    addedge(adj,0,4,1,indegree);
    addedge(adj,1,2,3,indegree);
    addedge(adj,4,2,2,indegree);
    addedge(adj,2,3,6,indegree);
    addedge(adj,4,5,4,indegree);
    addedge(adj,5,3,1,indegree);
    cout<<"Enter the source node:";
    cin>>node;
    mincost(adj,node,6,indegree);
    return 0;
}

