#include <bits/stdc++.h>
using namespace std;

/*
    1
    /\
    2 3
    /\ \
    4 5 6

6 1 2 1 3 2 4 2 5 3 6
---> 1 2 6 3 5 7
*/

int main() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for (int i=0;i<n-1;i++) {
        int u,v;cin>>u>>v;u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs;
    vector<bool> visited(n,false);
    queue<int> q;
    int root=0; 
    visited[root]=true;
    q.push(root);
    while (!q.empty()) {
        int curr=q.front();q.pop();
        bfs.push_back(curr);
        for (auto neigh:adj[curr]) {
            if (!visited[neigh]) {
                q.push(neigh);
                visited[neigh]=true;
            }
        }
    }
    for (int node:bfs) cout<<node+1<<" ";
    return 0;
}
