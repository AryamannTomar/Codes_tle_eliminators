#include<bits/stdc++.h>
using namespace std;
/*
P1 Block Sequence
Beautiful Sequence like 3_345_2_61
Find minimum number of deletions required to make the sequence beautiful
max no of elements we can pick up from i to n-1 elements;
dp[i]=max(dp[i+1],1+a[i]+dp[i+1+a[i]])
*/
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    
    vector<int> dp(n+1);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        int pick=0;
        if(i+arr[i]<=n-1){ 
            pick=1+arr[i];
            if(i+1+arr[i]<=n-1) pick+=dp[i+1+arr[i]];
        }
        int skip=0;
        if(i+1<=n-1) skip=dp[i+1];
        dp[i]=max(pick,skip);
    }
    cout<<n-dp[0];
};

/*
Color with Occurrences

*/