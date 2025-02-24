#include <bits/stdc++.h>
using namespace std;

vector<double> dp(5,-1);
auto f=[&](int n, auto &&F)->int{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=1.5+0.5*(F(n-1,F)+F(n/2,F));
};

int main(){ 
    cout<<f(5,f)<<endl;
    return 0;
}