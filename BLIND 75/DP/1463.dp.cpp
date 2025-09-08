#include <bits/stdc++.h>
using namespace std;

//recursion with memo 

 int recursion(int i,int j,int k,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
       //base case
       int m=grid.size();//rows
       int n=grid[0].size();
       if(i==m-1){
        return (j==k)?grid[i][j]:grid[i][j]+grid[i][k];
       }
       if(dp[i][j][k]!=-1) return dp[i][j][k];
       int maxi=-1e9;
       for(int col1=j-1;col1<=j+1;col1++){
         for(int col2=k-1;col2<=k+1;col2++){
           if(col1>=0 && col1<n && col2>=0 && col2<n){
            int current_val=(j==k)?grid[i][j]:grid[i][j]+grid[i][k];
            current_val+=recursion(i+1,col1,col2,grid,dp);
            maxi=max(maxi,current_val);
           }
         }
       }
       return dp[i][j][k]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();//rows
        int n=grid[0].size();//colums
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return recursion(0,0,n-1,grid,dp);
    }
    //this took some but we are not able to do it 
    //recursion with memo not lets try this with iteration
    
  //tabulation now

      int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();//rows
        int n=grid[0].size();//colums
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        for(int i=m-1;i>=0;i--){
          for(int j=n-1;j>=0;j--){
            for(int k=n-1;k>=0;k--){
 if(i==m-1) {
    dp[i][j][k]=(j==k)?grid[i][j]:grid[i][j]+grid[i][k];//base case
    continue;
 }
 //khela shuru hoga jab i banega m-2;
//mere fix i par mujhe j j+1 k +1 vgera chahiye 
//ab mai i+1 to lunga hi lunga but j k vala patter bhi to lena hai 
int maxi=-1e9;
       for(int col1=j-1;col1<=j+1;col1++){
         for(int col2=k-1;col2<=k+1;col2++){
           if(col1>=0 && col1<n && col2>=0 && col2<n){
            int current_val=(j==k)?grid[i][j]:grid[i][j]+grid[i][k];
            current_val+=dp[i+1][col1][col2];
            maxi=max(maxi,current_val);
           }
         }
       }
       dp[i][j][k]=maxi;

            }
          }
        }
        return dp[0][0][n-1];
    }

    //tabulation with space optimization
     int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();//rows
        int n=grid[0].size();//colums
       vector<vector<int>> prev(n, vector<int>(n, -1));
       vector<vector<int>> curr(n, vector<int>(n, -1));
        for(int i=m-1;i>=0;i--){
          for(int j=n-1;j>=0;j--){
            for(int k=n-1;k>=0;k--){
 if(i==m-1) {
    curr[j][k]=(j==k)?grid[i][j]:grid[i][j]+grid[i][k];//base case
    continue;
 }
 //khela shuru hoga jab i banega m-2;
//mere fix i par mujhe j j+1 k +1 vgera chahiye 
//ab mai i+1 to lunga hi lunga but j k vala patter bhi to lena hai 
int maxi=-1e9;
       for(int col1=j-1;col1<=j+1;col1++){
         for(int col2=k-1;col2<=k+1;col2++){
           if(col1>=0 && col1<n && col2>=0 && col2<n){
            int current_val=(j==k)?grid[i][j]:grid[i][j]+grid[i][k];
            current_val+=prev[col1][col2];
            maxi=max(maxi,current_val);
           }
         }
       }
       curr[j][k]=maxi;

            }
          }
          //i change yaha hoga 
          prev=curr;
        }
        return prev[0][n-1];
    }

int main(){

return 0;
}