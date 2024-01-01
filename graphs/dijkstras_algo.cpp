#include<iostream>
#include<vector>
#include<set>
using namespace std;

void addedge(vector<pair<int,int>> adj[],int u,int v,int w){
    adj[u].push_back(make_pair(w,v));
    adj[v].push_back(make_pair(w,u));
}

vector<int> dijkstra(vector<pair<int,int>> adj[],int s,int v){
    set<pair<int,int>> st;
    vector<int> dist;
    for(int i=0;i<v;i++){
        if(i==0) dist.push_back(0);
        else dist.push_back(INT8_MAX);
    }
    st.insert(make_pair(s,0));
    while(!st.empty()){
        auto curr=*(st.begin());
        int curr_dist=curr.first;
        int curr_node=curr.second;
        st.erase(st.begin());
        for(auto neighbour:adj[curr_node]){
            if(dist[neighbour.second]>curr_dist+neighbour.first){
                //dist[neighbour.first]=dist[curr_node]+dist[neighbour.first]
                auto rec=st.find(make_pair(dist[neighbour.second],neighbour.second));
                if(rec!=st.end()){
                    st.erase(make_pair(dist[neighbour.second],neighbour.second));
                }
                dist[neighbour.second]=curr_dist+neighbour.first;
                st.insert(make_pair(dist[neighbour.second],neighbour.second));
            }
        }

    }
    return dist;
}

int main(){
    vector<pair<int,int>> adj[5];
    int src;
    addedge(adj,0,1,7);
    addedge(adj,0,2,1);
    addedge(adj,0,3,2);
    addedge(adj,1,2,3);
    addedge(adj,1,3,5);
    addedge(adj,1,4,1);
    addedge(adj,3,4,7);
    cin>>src;
    vector<int> res=dijkstra(adj,src,5);
    for(int i=0;i<5;i++){
        cout<<"Distance from "<<src<<" to "<<i<<":"<<res[i]<<endl;
    }
    return 0;
}