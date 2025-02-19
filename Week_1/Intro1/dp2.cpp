#include <bits/stdc++.h>
using namespace std;
// Iterative Fibo, Grid Problem, Max AdjacentSum

/*
1 FIBO
*/
vector<int> dp(100,-1);
int fibo(int x){
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=x;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[x+1];
}

/*
2 GRID Prob
*/
int gridProb(int n, int m, vector<vector<int>> grid, vector<vector<int>> dp){
    vector<vector<int>> dp2(m,vector<int>(n,INT_MAX));
    dp[n-1][m-1]=grid[n-1][m-1];
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i<n-1) dp[i][j]=min(dp[i][j], grid[i][j]+dp[i+1][j]);
            if(j<m-1) dp[i][j]=min(dp[i][j], grid[i][j]+dp[i][j+1]);
        }
    }
    return dp[0][0];
}


/*
3 Max AdjacentSum
*/
int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n+1,0);
    dp[n]=0;
    for(int i=n-1; i>=0; i--){
        int pick=0,skip=0;
        if(i+2<n){
            pick=nums[i]+dp[i+2];
        }else{
            pick=nums[i];
        }
        skip=dp[i+1];
        dp[i]=max(pick,skip);
    }
    return dp[0];
}