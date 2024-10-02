
 // recursion with memorization apprach top down 
#include <bits/stdc++.h>
using namespace std;
#define lil long long int
 
     //write your code
 // recursion with memorization apprach top down 
 /*
  lil solve(lil index,lil sum,vector<lil> &arr,vector<vector<int>> &dp){
   if(sum==0) return 0;
   int n=arr.size();
   if(index==n) return 1e7;
   if(dp[index][sum]!=-1) return dp[index][sum];
   lil take=(sum>=arr[index])?1+solve(index,sum-arr[index],arr,dp):1e7;
   lil notTake=solve(index+1,sum,arr,dp);
   return dp[index][sum]=min(take,notTake);
 }
 */

//ierative approach
lil solve(){
      lil n,x;
      cin>>n>>x;
   vector<lil> arr(n,0);
       for(lil i=0;i<n;i++){
           cin>>arr[i];
       }
    sort(arr.begin(),arr.end());
    vector<lil> dp(x+1,1e9);
    dp[0]=0;
    for(lil i=1;i<=x;i++){
      for(int j=0;j<n;j++){
        if(arr[j]>i) break;
       dp[i]=min(dp[i],1+dp[i-arr[j]]);
       }
        }
   if(dp[x]>=1e9) return -1;
   return dp[x];
  }


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
      lil n,x;
      cin>>n>>x;
      vector<vector<int>> dp(n,vector<int> (x+1,-1));
       vector<lil> arr(n,0);
       for(lil i=0;i<n;i++){
           cin>>arr[i];
       }
       sort(arr.begin(),arr.end());
   lil val=solve(0,x,arr,dp);
   val=(val>=1e7)?-1:val;
   cout<<val;
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA