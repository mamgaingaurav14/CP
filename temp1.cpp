
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   lil t;
   cin>>t;

    while(t--){
    int n;vector<int> vec(n);
    cin>>n;
    for(int i=0;i<n;i++) cin>>vec[i];
    int dp[n+1][n+1][n+1];
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++) {
        if(j==0) dp[n][i][j]=i;
        else dp[n][i][j]=0;//puri ni karpaye to zero
      }
    }
    for(int i=n-1;i>=0;i--){
       for(int j=1;j<=n;j++){
         for(int k=0;k<j;k++){
             if(k>0){
              if(vec[i]==j) dp[i][j][k]=dp[i+1][j][k-1];//take 
              else dp[i][j][k]=dp[i+1][j][k]; //no take 
             }
             else{
               dp[i][j][k]=  max(j+dp[i+1][vec[i]][vec[i]-1],dp[i+1][j][k]);
             }
         }
       }
    }
    cout<<dp[0][][0]
   
    }
    
}
 
 
//Jai Hind