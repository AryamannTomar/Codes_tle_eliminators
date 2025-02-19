#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<vector<double>> dp(n, vector<double>(n+1,0));
    dp[0][0]=1-p[0];
    dp[0][1]=p[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i+1;j++){
            if(j==0) dp[i][0]=dp[i-1][0]*(1-p[i]);
            else dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }
    }
    // Final ans 
    double sum=0;  
    for(int j=(n/2)+1;j<=n;j++){
        sum+=dp[n-1][j];
    }
    cout<<fixed<<setprecision(9)<<sum;
}
