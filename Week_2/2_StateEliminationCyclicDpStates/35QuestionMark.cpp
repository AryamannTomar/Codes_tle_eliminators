#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n,-1)));

}

auto f=[&](int index, int threes, int fives, auto &&F) -> int {
    if(index==n) return 0;
    if(dp[index][threes][fives]!=-1) return dp[index][threes][fives];
    if(arr[index]!='?'){
        return (arr[index]=='3'?three[index]:five[index])+
        F(index+1,threes+(arr[index]=='3'), fives+(arr[index]=='5'),F);
    }
    int answer=-1e8;
    if(threes<=k1) answer=max(answer,three[index]+F(index+1,threes+1,fives,F));
    if(fives<=k2) answer=max(answer,five[index]+F(index+1,threes,fives+1,F));
    return dp[index][threes][fives]=answer;
};

auto f1=[&](int index, int threes, int fives, auto &&F1) -> int {
    if(index==n) return 0;
    if(dp[index][threes][fives]!=-1) return dp[index][threes][fives];
    if(arr[index]!='?'){
        return (arr[index]=='3'?three[index]:five[index])+
        F1(index+1,threes+(arr[index]=='3'), fives+(arr[index]=='5'),F1);
    }
    int answer=-1e8;
    if(threes<=k1) answer=max(answer,three[index]+F(index+1,threes+1,fives,F1));
    if(fives<=k2) answer=max(answer,five[index]+F(index+1,threes,fives+1,F1));
    return dp[index][threes][fives]=answer;
};

int main(){
    
}