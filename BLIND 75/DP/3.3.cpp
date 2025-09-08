//dp problem longest increaing subsequence
#include <bits/stdc++.h>
using namespace std;

//recursion only
  int answer(int index,vector<int> &nums,int prev_index){
        if(index==nums.size()) return 0;
        int notTake=0+answer(index+1,nums,prev_index);
        int take=-1e9;
        if(prev_index==-1 || nums[index]>nums[prev_index]){
            take=1+answer(index+1,nums,index);
        }
        return max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev_index=-1;
        return answer(0,nums,prev_index);
    }

    //recursion with memorization

   int answer(int index,vector<int> &nums,int prev_index,vector<vector<int>> &dp){
        if(index==nums.size()+1) return dp[index][prev_index]=0;
        if(dp[index][prev_index]!=-1) return dp[index][prev_index];
        //all fine
        int notTake=0+answer(index+1,nums,prev_index,dp);
        int take=-1e9;
        if(prev_index==0 || nums[index-1]>nums[prev_index-1]){
            take=1+answer(index+1,nums,index,dp);
        }
        return dp[index][prev_index]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+1,-1));
        return answer(1,nums,0,dp);
    }

//the most important point here was how 
//to make the recurrence relation 
    //tabulation again hard to grasp
  int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int index=n-1;index>=0;index--){
            for(int prev_index=index-1;prev_index>=-1;prev_index--){
               int notTake=dp[index+1][prev_index+1];
               int take=-1e9;
               if(prev_index==-1 || nums[index]>nums[prev_index] ){
                take=1+dp[index+1][index+1];
               }
               dp[index][prev_index+1]=max(take,notTake);
            }
        }
        return dp[0][-1+1];
    }

    //space optimization also important 
      int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> prev(n+1);
        vector<int> curr(n+1);
        for(int index=n-1;index>=0;index--){
            for(int prev_index=index-1;prev_index>=-1;prev_index--){
               int notTake=prev[prev_index+1];
               int take=-1e9;
               if(prev_index==-1 || nums[index]>nums[prev_index] ){
                take=1+prev[index+1];
               }
               curr[prev_index+1]=max(take,notTake);
            }
            prev=curr;
        }
        return prev[-1+1];
    }
