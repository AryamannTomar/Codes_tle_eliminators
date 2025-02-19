#include <bits/stdc++.h>
using namespace std;

/*
1 FIBO
*/
int dp[42];
int fibo(int n){
    if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibo(n-1)+fibo(n-2);
}

/*
2 GRID Prob
*/
int helper(int i,int j,int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if((i>m-1)||(j>n-1)) return INT_MAX;
    if((i==m-1)&(j==n-1)) return grid[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=grid[i][j]+min(helper(i+1,j,m,n,grid,dp),helper(i,j+1,m,n,grid,dp));
}

/*
3 Max Adjacent Sum
*/
/*
M1
dp[i]=max(a[i]+dp[i+2],dp[i+1]);
ans=dp[0]
*/
int fn(int i, int n, vector<int>& nums, vector<int>& dp){
    if(i>n-1) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(nums[i]+fn(i+2,n,nums,dp),fn(i+1,n,nums,dp));
}

/*
M2
state
dp[i][0] dont pick ith element
dp[i][1] pick ith element

transition eqn
dp[i][0] : dp[i+1][0] or dp[i+1][1]
dp[i][1] : a[i]+dp[i+1][0]

trivial case
dp[n-1][0]=0
dp[n-1][1]=a[n-1]

ans=max(dp[0][0],dp[0][1])
*/

// ***************************************************************************************************************************************