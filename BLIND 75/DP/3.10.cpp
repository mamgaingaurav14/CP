//jump game 
#include <bits/stdc++.h>
using namespace std;

//recursion with memorisation approach
bool recursion(int index,vector<int> &nums,vector<int> &dp){
    if(index==0) return 1;
    if(dp[index]!=-1) return dp[index];

    for(int i=index-1;i>=0;i--){
        if(nums[i]>=index-i){
            //point from where i can reach the index step
            if(recursion(i,nums,dp)) return dp[index]=1;
        }
    }
    return dp[index]=0;
}

 bool canJump(vector<int>& nums) {
        int n=nums.size();
        int index=n-1;
        vector<int> dp(n+1,-1);
        return recursion(index,nums,dp);
    }

//let me try tabulation apporach

//tle approach since it is taking two loops
  bool canJump(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<bool> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            //har index pr individual phchne ka rasta batao
            for(int j=0;j<i;j++){
              if(dp[j]==1 && nums[j]>=i-j) dp[i]=true;
            }
        }
        return dp[n-1];
    }
//good approach one loop
bool canJump(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<bool> dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
          //ab yaha se jaha tak mai ja skta hun vha tk sb 1 krdunga 
          if(dp[i]){
            int max_jump=min(n-1,i+nums[i]);
            for(int j=i+1;j<=max_jump;j++) dp[j]=1;
          }
        }
        return dp[n-1];
    }
int main(){
  return 0;
}