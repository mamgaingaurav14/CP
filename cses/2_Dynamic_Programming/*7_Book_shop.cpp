
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

 
  //greedy wont wokr here i checked thourghly
  //main point here is undersating that index loop has to come first and then after the sum/answer loop always 
  int solve(){
      int n,x;
      cin>>n>>x;
       vector<int> prices(n),pages(n);
       for(int i=0;i<n;i++) cin>>prices[i];
       for(int i=0;i<n;i++) cin>>pages[i];
      vector<vector<int>> dp(n+1,vector<int> (x+1,0));
      for(int i=n-1;i>=0;i--){
        for(int j=1;j<=x;j++){
          dp[i][j]=dp[i+1][j];//skip vala part with same price
         if(j>=prices[i]) dp[i][j]=max(pages[i]+dp[i+1][j-prices[i]],dp[i][j]);
        }
      }
      return dp[0][x];
 }

 // more optimised with the help of prev and curr and 1d array 
  int solve(){
      int n,x;
      cin>>n>>x;
       vector<int> prices(n),pages(n);
       for(int i=0;i<n;i++) cin>>prices[i];
       for(int i=0;i<n;i++) cin>>pages[i];
      vector<int> prev(x+1,0);
      for(int i=n-1;i>=0;i--){
        vector<int> dp(x+1,0);
        for(int j=1;j<=x;j++){
          dp[j]=prev[j];//skip vala part with same price
         if(j>=prices[i]) dp[j]=max(pages[i]+prev[j-prices[i]],dp[j]);
        }
        prev=dp;
      }
      return prev[x];
 }
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 cout<< solve();
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA