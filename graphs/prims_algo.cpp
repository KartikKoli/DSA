#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

#define v 4

int min(int a,int b){
    return (a<b)?a:b;
}

int prim_mst(int graph[v][v]){
    bool mset[v]={false};
    int key[v];
    for(int i=0;i<v;i++){
        key[i]=INT8_MAX;
    }
    key[0]=0;
    int res=0;
    for(int count=0;count<v;count++){
        int u=-1;
        for(int i=0;i<v;i++){
            if(!mset[i] && (u==-1 || key[i]<key[u])) u=i;
        }
        res+=key[u];
        mset[u]=true;
        for(int x=0;x<v;x++){
            if(graph[u][x]!=0 && !mset[x]){
                key[x]=min(key[x],graph[u][x]);
            }
        }
    }
    return res;
}

int main(){
    int graph[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i!=j){
                cout<<"Enter weight from "<<i<<" to "<<j<<":";
                cin>>graph[i][j];
            }
            else{
                graph[i][j]=0;
            }
        }
    }
    int res=prim_mst(graph);
    cout<<"Cost of MST:"<<res;
    return 0;
}