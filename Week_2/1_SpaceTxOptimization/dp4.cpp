#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, X;
    cin>>n>>X;
    vector<int> prices(n), pages(n);
    for(auto &p: prices) cin>>p;
    for(auto &p: pages) cin>>p;
    vector<vector<int>> dp(n+1, vector<int>(X+1,0));
    // for(int i=n-1;i>=0;i--){
    //     for(int b=0;b<=X;b++){
    //         int pick=0, skip=0;
    //         if(b>=prices[i]) pick=pages[i]+dp[i+1][b-prices[i]];
    //         skip=dp[i+1][b];
    //         dp[i][b]=max(pick,skip);
    //     }
    // }
    vector<int> curr(x+1), next(x+1,0);
    for(int i=n-1;i>=0;i--){
        for(int b=0;b<=X;b++){
            int pick=0, skip=0;
            if(b>=prices[i]) pick=pages[i]+next[b-prices[i]];
            skip=next[b];
            curr[b]=max(pick,skip);
        }
        next=curr;
    }


    cout<<dp[0][X];
    /*
    TC = num of states * TT per state
    TC = O(N*X)*O(1)=>O(N*X)
    n=1000 X=100000 TC=1e8 operations
    dp[b][i] will give TLE
    */
    return 0;
}