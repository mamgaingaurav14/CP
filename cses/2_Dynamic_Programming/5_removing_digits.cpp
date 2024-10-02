
 
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define lil long long int
 
     //write your code

     //tabulation is still faster than recursion here 
     lil solve(lil n) {
    vector<lil> dp(n + 1, 1e9);  // Initialize dp array with a large value
    dp[0] = 0;  // Base case
    for (lil i = 1; i <= n; ++i) {
        lil copy = i;
        while (copy > 0) {
            lil bit = copy % 10;
            copy /= 10;
            if (bit != 0) {
                dp[i] = min(dp[i], dp[i - bit] + 1);
            }
        }
    }

    return dp[n];
}

  lil solve(lil n,vector<lil> &dp){
    if(n==0) return 0;
    if(n<0) return 1e9;
    if(dp[n]!=-1) return dp[n];
    lil copy=n;
    lil mini=1e9;
    while(copy){
       lil bit=copy%10;
       copy/=10;
       if(!bit) continue;
       mini=min(mini,1+solve((n-bit),dp));
    }
 return dp[n]=mini;
 }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   lil n;
   cin>>n;
   vector<lil> dp(n+1,-1);
   cout<<solve(n,dp);
    
}
 
 
//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA