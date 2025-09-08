int perfectSum(vector<int>& arr, int target) {
        // code here
        //optimal 
        int n=arr.size();
        int dp[n+1][target+1];
        for(int i=0;i<=target;i++) dp[n][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=n-1;i>=0;i--){
          for(int j=0;j<=target;j++){
              dp[i][j]=dp[i+1][j];//not take
              if(j>=arr[i]) dp[i][j]+=dp[i+1][j-arr[i]];
          }
        }
        return dp[0][target];
    }