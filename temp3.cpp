
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code
     
  lil solve(){
      lil n,x;
      cin>>n>>x;
   vector<lil> arr(n,0);
       for(lil i=0;i<n;i++){
          cin>>arr[i];
    }
    sort(arr.rbegin(),arr.rend());
    vector<vector<lil>> dp(x+1,vector<lil> (n+1,0));
    for(lil a=0;a<=n;a++){
      dp[0][a]=1;
    }
    for(lil i=1;i<=x;i++){//sum
      for(lil j=n-1;j>=0;j--){//staring from index no
       dp[i][j]=dp[i][j+1];
       if(i<arr[j]) continue;
       dp[i][j]=(dp[i][j]+(dp[i-arr[j]][j]%MOD))%MOD;
       }
        }
   return dp[x][0];
  }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve();
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA