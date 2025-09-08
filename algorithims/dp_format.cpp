
//1d dp format 

//2d dp format
int change(int amount, vector<int>& coins) {
        int n=coins.size();
        unsigned long long dp[n+1][amount+1];
        for(int i=0;i<=amount;i++) dp[n][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=n-1;i>=0;i--){ 
         for(int j=0;j<=amount;j++){
            dp[i][j]=dp[i+1][j];//not taken
            if(j>=coins[i]) dp[i][j]+=dp[i][j-coins[i]];
         }
        }
        return dp[0][amount];
    }

//3d dp format

    