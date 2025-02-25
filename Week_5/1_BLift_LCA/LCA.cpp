#include <bits/stdc++.h>
using namespace std;

int lift(int u, int k){
    for(int j=0;j<LOG;j++) 
        if((k>>j)&1)
            u=anc[u][j]
    return u;
}

int lca(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);
    if(depth[u]>depth[v]) u=lift(u,depth[u]-depth[v]);
    if(u==v) return u;
    for(int j=LOG-1;j>=0;j--){
        if(anc[u][j]!=anc[v][j]){
            u=anc[u][j];
            v=anc[v][j];
        }
    }
    return anc[u][0];
}

int main(){
    
    return 0;
}