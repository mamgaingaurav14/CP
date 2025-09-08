#include <bits/stdc++.h>
using namespace std;

//dp with memo
  int recursion(int index,int prev,vector<int> &nums,vector<vector<int>> &dp){
        //base case
        int n=nums.size();
        if(index==n) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int notTake=recursion(index+1,prev,nums,dp);
        //int take is the real job here
        int take=INT_MIN;
        if(prev==-1 || (nums[index]%2)!=prev){
            int temp=nums[index]%2;
            take=1+recursion(index+1,temp,nums,dp);
        }
        return dp[index][prev+1]=max(notTake,take);

    }
    int maximumLength(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        if(n<=2) return 2;
        vector<vector<int>> dp(n+1,vector<int> (3,-1));
        int even=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%2==0) even++;//sare even
        }
        even=max(even,n-even);
        int prev=-1;
        return max(recursion(index,prev,nums,dp),even);
    }

//observation answer
    int odd_eve(int rev,vector<int> &nums){
        int count=0;
       for(int i=0;i<nums.size();i++){
         if(nums[i]%2==rev){
            count++;
            rev=(rev?0:1);
         } 
     }
     return count;
     }
    int maximumLength(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        int even=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%2==0) even++;//sare even
        }
        even=max(even,n-even);
        even=max(even,odd_eve(0,nums));
        even=max(even,odd_eve(1,nums));
        return even;
    }

    //next level 3d question 
       int recursion(int index,int prev,vector<int> &nums,vector<vector<vector<int> > >&dp,int prev_element,int k){
        //base case
        int n=nums.size();
        if(index==n) return 0;
        if(dp[index][prev+2][prev_element+1]!=-1) return 0;

        //yaha tak thik hai 
        int notTake=recursion(index+1,prev,nums,dp,prev_element,k);
        //int take is the real job here
        int take=INT_MIN;
        if(prev==-2 || prev==-1 || (nums[index]+nums[prev_element])%k==prev){
            if(prev==-1) prev=(nums[index]+nums[prev_element])%k;
            if(prev==-2) prev=-1;
            prev_element=index;//this is fine
            take=1+recursion(index+1,prev,nums,dp,prev_element,k);
        }
        return dp[index][prev+2][prev_element+1]=max(notTake,take);
    }
    int maximumLength(vector<int>& nums,int k) {
        int index=0;
        int n=nums.size();
        if(n<=2) return 2;
        if(k==1) return n;
       vector<vector<vector<int> > > dp(
          n+1, vector<vector<int> >(k+2, vector<int>(n+2,-1)));
        int prev=-2;
        int prev_element=-1;
        return recursion(index,prev,nums,dp,prev_element,k);
    }
    //what if i dont send the previous element instead i give 
    //prev element index woaah

