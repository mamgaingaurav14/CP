#include <bits/stdc++.h>
using namespace std;

//recursion with memorization
int fibonacci(int n,unordered_map<int,int> &dp){
   if(n<=1) return n;
   if(dp.count(n)) return dp[n];
   int answer= fibonacci(n-1,dp)+fibonacci(n-2,dp);
   dp[n]=answer;
   return answer;
}
//emmorization is storing already
//solved subrpoblems
//tabulation which is iterative
int fibonacci_tabulation(int n){
  vector<int> dp(n+1,0);
  dp[0]=0;
  dp[1]=1;
  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  return dp[n];
}

//tabulation with space optimization

int fibonacci_tabulation(int n){
  if(n<=1) return n;
  int prev1=0;
  int prev2=1;
  for(int i=2;i<=n;i++){
    int temp=prev2;
    prev2 =prev1+prev2;
    prev1=temp;
  }
  return prev2;
}

//here we even removed the need
//of storing previous values other 
//just 2 values 
int main(){
unordered_map<int,int> dp;
 cout<<fibonacci_tabulation(6);

}
//iterative 


