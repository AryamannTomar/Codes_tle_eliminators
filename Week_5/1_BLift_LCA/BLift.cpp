#include <bits/stdc++.h>
using namespace std;

/*
    ancestor[u][k] -> 2^k-th ancestor of node u
    anc[u][k] depends on anc[u][k-1] thats why k dimension comes outside the for loop
*/
void CalcAncestors(){
    for(int k=1;k<LOG;k++){
        for(int u=1;u<=n;u++){
            anc[u][k]=anc[anc[u][k-1]][k-1];
        }
    }
}

int lift(int u, int k){
    for(int j=0;j<LOG;j++) 
        if((k>>j)&1)
            u=anc[u][j]
    return u;
}

int main(){
    return 0;
}