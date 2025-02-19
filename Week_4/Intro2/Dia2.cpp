#include <bits/stdc++.h>
using namespace std;

/*
    1
    /\
    2 3
    /\ \
    4 5 6

6 1 2 1 3 2 4 2 5 3 6
---> 4
*/

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& dist){
    for (auto neigh:adj[node]) {
        if (neigh!=parent) {
            dist[neigh]=dist[node]+1;
            dfs(neigh,node,adj,dist);
        }
    }
}
int main(){
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n+1);
    // doing dfs from 1st node / random node also works
    dist[1]=0;
    dfs(1,0,adj,dist);
    int maxDist=0,node=1;
    for(int i=1;i<=n;i++){
        if (dist[i]>maxDist){
            maxDist=dist[i];
            node=i;
        }
    }
        
    for (int i=1;i<=n;i++) dist[i]=0;
    // node is one end of diameter, now doing dfs from this end 
    dfs(node,0,adj,dist);
    maxDist=0;
    for(int i=1;i<=n;i++) maxDist=max(maxDist,dist[i]);
    cout<<maxDist<<endl;
    return 0;
}