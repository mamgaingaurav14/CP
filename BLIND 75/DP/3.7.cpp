//house robber question
#include <bits/stdc++.h>
using namespace std;

//easy peezy solution approach 1
//recursion with memorisation
     int recursion(int index,vector<int> nums,vector<int> &dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int notTake=recursion(index+1,nums,dp);
        int take=nums[index]+recursion(index+2,nums,dp);
        return dp[index]=max(notTake,take);
     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int index=0;
        return recursion(index,nums,dp);
    }

    //dp top bottm apporaach
    //very easy problem it is bro 
    //you can also use space optimization very easily dude
      int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
          int notTake=dp[i+1];
          int take=nums[i]+dp[i+2];
          dp[i]=max(notTake,take);
        }
        return dp[0];
    }
int main(){

}