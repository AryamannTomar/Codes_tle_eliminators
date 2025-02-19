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

void dfs(int curr, vector<vector<int>>& adj, int parent, vector<int>& A){
    A[curr]=0;
    for(int neigh: adj[curr]){
        if (neigh!=parent){
            dfs(neigh,adj,curr,A);
            A[curr]=max(A[curr],1+A[neigh]);
        }
    }
}

void dfs1(int curr, vector<vector<int>>& adj, int parent, vector<int>& A, vector<int>& maxDist){
    vector<int> numLeaves;
    for(int neigh: adj[curr]){
        if (neigh!=parent){
            numLeaves.push_back(A[neigh]);
            dfs1(neigh,adj,curr,A, maxDist);
        }
    }
    if(numLeaves.size()==0) maxDist[curr]=0;
    else if(numLeaves.size()==1) numLeaves[0]+1;
    else{
        sort(numLeaves.begin(), numLeaves.end());
        reverse(numLeaves.begin(), numLeaves.end());
        maxDist[curr]=numLeaves[0]+numLeaves[1]+2;
    }
}

int main(){    
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root=0;
    vector<int> A(n,-1); // max distance of any leaf from current node in subtree
    vector<int> maxDistAsLCA(n,-1); // stores maximum distance of a path such that current node is LCA of that path
    dfs(0,adj,-1,A);
    dfs1(0,adj,-1,A,maxDistAsLCA);
    int dia=0;
    for(int i=0;i<maxDistAsLCA.size();i++) dia=max(dia,maxDistAsLCA[i]);
    cout<<dia;
    return 0;
}