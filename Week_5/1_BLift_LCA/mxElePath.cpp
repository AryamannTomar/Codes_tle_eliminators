#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<=n-1;i++) cin>>a[i];
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int LOG=18;
    vector<vector<int>> par(n+1,vector<int>(LOG));
    vector<int> depth(n+1);
    vector<long long> sum_from_root(n+1,0);
    vector<vector<int>> mx(n+1,vector<int>(LOG));
    
    auto dfs=[&](auto&& dfs, int u, int p)->void{
        par[u][0]=p;
        depth[u]=depth[p]+1;
        sum_from_root[u]=sum_from_root[p]+a[u];
        mx[u][0]=a[u];
        for(int v:adj[u]){
            if(v==p) continue;
            dfs(dfs,v,u);
        }
    };
    dfs(dfs,1,0);

    for(int j=0;j<LOG;j++){
        for(int u=1;u<=n;u++){
            int mid=par[u][j-1];
            par[u][j]=par[mid][j-1];
            mx[u][j]=max(mx[u][j-1],mx[mid][j-1]);
        }
    }

    auto lift=[&](int u, int k){
        for(int j=0;j<LOG;j++){
            if((k>>j)&1) u=par[u][j];
        }
        return u;
    };

    auto get_max=[&](int u, int k){
        int ans=0;
        for(int j=0;j<LOG;j++){
            if((k>>j)&1){
                ans=max(ans,mx[u][j]);
                u=par[u][j];
            }
        }
        return u;
    };

    auto lca=[&](int u, int v){
        if(depth[u]<depth[v]) swap(u,v);
        if(depth[u]>depth[v]) u=lift(u,depth[u]-depth[v]);
        if(u==v) return u;
        for(int j=LOG-1;j>=0;j--){
            if(par[u][j]!=par[v][j]){
                u=par[u][j];
                v=par[v][j];
            }
        }
        return par[u][0];
    };
    /*
    ========================================================================================
    Q1 distance u,v
    Q2 Sum of nodes u,v inclusive
    Q3 Max Node in path from u to v
    */
    auto dist=[&](int u, int v){
        return depth[u]+depth[v]-2*depth[lca(u,v)];
    };
    auto sum_path=[&](int u, int v){
        return sum_from_root[u]+sum_from_root[v]-2*sum_from_root[lca(u,v)]+a[lca(u,v)];
    };
    auto max_path=[&](int u, int v){
        int l=lca(u,v);
        return max(get_max(u,depth[u]-depth[l]), get_max(v,depth[v]-depth[l]),a[l]);
    };

    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
    }
    return 0;
}
