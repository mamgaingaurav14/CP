#include <bits/stdc++.h>
using namespace std;
//coin change problem 
/*conisdering  i am new to dp but i will 
try my best to solve the problem */
//works


//the apporach is al about unerstanding recursion
//then making a recursion tree and doing it 
//it will take time but it will happen 

// memorization and recursion technique
 int fun(int index,int target,vector<int> &arr,vector<vector<int>> &dp){
     //base case
     if(index==0){
        if(!(target%arr[0])) return dp[index][target]=(target/arr[0]);
        return 1e9;
     }
     if(dp[index][target]!=-1) return dp[index][target];
     int notTake=0+fun(index-1,target,arr,dp);
     int take=1e9;
     if(arr[index]<=target){
         take=1+fun(index,target-arr[index],arr,dp);
     }
     return dp[index][target]=min(take,notTake);

  }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int t=amount;
        vector<vector<int>> dp(n,vector<int> (t+1,-1));
        int ans= fun(n-1,t,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }



    //tabulation method code
    //the core recursion equation remains the same

     int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int t=amount;
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=t;j++){
               //base case
               if(i==0){
                 if(j%coins[i]==0){
                      dp[i][j]=j/coins[i];
                      continue;
                 }
                 else{
                     dp[i][j]=1e9;
                     continue;
                 }
               }
               int notTake=dp[i-1][j];
               int take=1e9;
               if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
               }
               dp[i][j]=min(take,notTake);
            }
        }
        int ans=dp[n-1][t];
        if(ans>=1e9) return -1;
        return ans;
    }
 
 //space optimization ach using previous 
 //and current vector arrays 
     int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int t=amount;
        vector<int> prev(t+1,0);
        vector<int> curr(t+1,0);
        for(int i=0;i<=t;i++){
            //case for 0 index and all targets 
            if((i%coins[0])==0){
                prev[i]=i/coins[0];
            }
            else{
                prev[i]=1e9;
            }   
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
               int notTake=prev[j];
               int take=1e9;
               if(coins[i]<=j){
                    take=1+curr[j-coins[i]];
               }
               curr[j]=min(take,notTake);
            }
            prev=curr;
        }
        int ans=prev[t];
        if(ans>=1e9) return -1;
        return ans;
    }

//last but the most
// effetive binary search approach


    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp={nums[0]};
        int len=1;
        for(int i=0;i<nums.size();i++){
          if(nums[i]>temp.back()) {
            temp.push_back(nums[i]);
            len++;
          }
          else{
            int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[ind]=nums[i];
          }
        }
      return len;
    }

    //understadning the use of lower bound
    //it gives the it which is greater or equal
    //to value given
int main(){
   vector<int> arr = {1, 2, 3};
    int T = 7;
    cout<<coinChange(arr,7);
}