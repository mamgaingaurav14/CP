
 
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
    sort(arr.begin(),arr.end());
    vector<lil> dp(x+1,0);
    dp[0]=1;
    for(lil i=1;i<=x;i++){
      bool flag=false;
      for(lil j=0;j<n;j++){
        if(arr[j]>i) break;
        if(dp[i-arr[j]]==-1) continue;
        flag=true;
        dp[i]=(dp[i]+dp[i-arr[j]]+MOD)%MOD;
       }
       if(!flag) dp[i]=-1;
        }
   if(dp[x]==-1) return 0;
   return dp[x];
  }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<solve();
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA