#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 10000007

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	int n=2;
	ll dp[2][n+1];
	// 1->D 0->{ABC}	
	dp[1][0]=1;
	dp[0][0]=0;
	for(int j=1;j<=n;j++){
		dp[1][j]=(3*dp[0][j-1])%M;
		dp[0][j]=(2*dp[0][j-1]+dp[1][j-1])%M;
	}
	cout<<dp[1][n];
}