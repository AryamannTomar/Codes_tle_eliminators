#include <bits/stdc++.h>
using namespace std;
int f(){
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int x=s.size(), y=t.size();
    string answer="";
    while(x>0 && y>0){
        if(s[x-1]==t[y-1]) answer+=s[x-1],x--,y--;
        else if(dp[x-1][y]==dp[x][y]) x--;
        else if(dp[x][y-1]==dp[x][y]) y--;
    }
    reverse(answer);
}

int main(){
    
    return 0;
}