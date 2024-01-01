#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
}

void dfsrec(vector<int> adj[],int s,bool visited[],stack<int> &st){
    visited[s]=true;
    for(int x:adj[s]){
        if(visited[x]==false) dfsrec(adj,x,visited,st);
    }
    st.push(s);
}

void dfs(vector<int> adj[],int v){
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    stack<int> s;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfsrec(adj,i,visited,s);
        }
    }
    while(s.empty()==false){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    vector<int> adj[5];
    addedge(adj,0,1);
    addedge(adj,1,3);
    addedge(adj,2,3);
    addedge(adj,2,4);
    addedge(adj,3,4);
    dfs(adj,5);
    return 0;
}