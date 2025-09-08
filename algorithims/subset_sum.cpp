 bool isSubsetSum(vector<int>& arr, int target) {
        // code here
       int n=arr.size();
       bool dp[n+1][target+1];
       for(int i=1;i<=target;i++) dp[n][i]=0;//any target from n index is not possible 
       for(int i=0;i<=n;i++) dp[i][0]=1;
        bool ans=false;
        for(int i=n-1;i>=0;i--){
           for(int j=0;j<=target;j++){
             dp[i][j]=dp[i+1][j];
             if(j>=arr[i]) dp[i][j]=dp[i][j] || dp[i+1][j-arr[i]];
          }
          if(dp[i][target]) return true;
        }
        return dp[0][target];
    }