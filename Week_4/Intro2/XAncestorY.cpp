#include <bits/stdc++.h>
using namespace std;

int globalTime=0;
vector<int> inTime(1e6), outTime(1e6);

void dfs(int curr, vector<vector<int>>& adj, int parent){
    globalTime++;
    inTime[curr]=globalTime;
    for(int neigh: adj[curr])
        if(neigh!=parent) dfs(neigh,adj,curr);
    globalTime++;
    outTime[curr]=globalTime;
}

int main(){
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,adj,-1);
    int q; cin>>q;
    while(q--){
        int x,y; cin>>x>>y;
        if((inTime[x]<inTime[y])&&(outTime[x]>outTime[y])) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
