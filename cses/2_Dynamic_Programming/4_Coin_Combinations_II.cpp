
 //waiting to be solved
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

 //removing the long long ints works actually
     //write your code
  int solve(){
      int n,x;
      cin>>n>>x;
   vector<int> arr(n,0);
       for(int i=0;i<n;i++){
          cin>>arr[i];
    }
    vector<vector<int>> dp(x+1,vector<int> (n+1,0));
    for(int a=0;a<=n;a++){
      dp[0][a]=1;
    }
    for(int i=1;i<=x;i++){//sum
      for(int j=n-1;j>=0;j--){//staring from index no
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