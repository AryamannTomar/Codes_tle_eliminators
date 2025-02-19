#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& a){
	vector<int> dp(n+1,1);
	for(int i=n-2;i>0;i--){
		int k=2;
	    for (int j=i*k;j<=n;k++,j=i*k){
	        if (a[j]>a[i]) dp[i]=max(1+dp[j],dp[i]);
	    }
	}
	int mx=0;
	for(int i=1;i<=n;i++) mx=max(mx,dp[i]);
	cout<<mx<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n+1);
		for(int i=1;i<=n;i++) cin>>arr[i];
		solve(n,arr);
	}
}