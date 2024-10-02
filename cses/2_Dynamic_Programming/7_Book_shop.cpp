
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

 
     //write your code
  int solve(){
      int n,x;
      cin>>n>>x;
       vector<int> Price(n),Pages(n);
       for(int i=0;i<n;i++){
           cin>>Price[i];
       }
       vector<vector<int>> dp(x+1,vector<int> (n+1,0));
       for(int i=0;i<n;i++){
           cin>>Pages[i];
       }
       for(int i=1;i<=x;i++){
         for(int j=n-1;j>=0;j--){
            dp[i][j]=dp[i][j+1];
            if(Price[j]>i) continue;
            dp[i][j]=max(dp[i][j],dp[i-Price[j]][j+1]+Pages[j]);
         }
       }
       return dp[x][0];
     //write your code

 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 cout<< solve();
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA