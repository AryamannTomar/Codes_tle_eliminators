#include <bits/stdc++.h>
using namespace std;

void CalcAncestors(){
    // ancestor[u][k] -> 2^k-th ancestor of node u
    for(int k=1;k<LOG;k++){
        for(int u=1;u<=n;u++){
            anc[u][k]=anc[anc[u][k-1]][k-1];
        }
    }
}

int main(){
    return 0;
}