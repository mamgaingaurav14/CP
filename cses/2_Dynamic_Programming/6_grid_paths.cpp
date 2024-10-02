
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 int n;
    

    //writing the recursive approach directly
  lil solve(){
      cin>>n;
      vector<vector<int>> dp(n,vector<int> (n,0));
      char c;
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
           cin>>c;
           if(c=='*') dp[i][j]=-1;
         }
      }
      if(dp[0][0]==-1) return 0;
      dp[0][0]=1;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(dp[i][j]==-1) continue;
           if(i+1<n && dp[i+1][j]!=-1) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
           if(j+1<n && dp[i][j+1]!=-1) dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MOD;
         }
      }
      if(dp[n-1][n-1]==-1) return 0;
      return dp[n-1][n-1];
     //write your code



 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve();
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA