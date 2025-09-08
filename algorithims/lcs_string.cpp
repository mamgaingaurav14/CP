   unordered_map<string,bool> mp;
void backtracking(string &ans,string &curr,vector<vector<int>> &dp,int i,int j,string &text1, string &text2,bool &flag){
    if(dp[i][j]==0){
        ans=curr;
        flag=true;
        return;
    }
    if(flag) return;
    string key=to_string(i)+to_string(j)+curr;
    if(mp[key]) return;
    mp[key]=true;
    if(text1[i]==text2[j]){
      curr.push_back(text1[i]);
      backtracking(ans,curr,dp,i+1,j+1,text1,text2,flag);
      curr.pop_back();
    }
    else{
      if(dp[i+1][j]==dp[i][j]) backtracking(ans,curr,dp,i+1,j,text1,text2,flag);
      if(dp[i][j+1]==dp[i][j]) backtracking(ans,curr,dp,i,j+1,text1,text2,flag);
    }
}

    string lcs(string text1, string text2) {
        // Code here
        int n=text1.size(),m=text2.size();
        int i=n-1,j=m-1;
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        for(int i=0;i<=m;i++) dp[n][i]=0;
        for(int i=0;i<=n;i++) dp[i][m]=0;
        for(int i=n-1;i>=0;i--){
          for(int j=m-1;j>=0;j--){
            if(text1[i]==text2[j])  dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
            else  dp[i][j]=max(dp[i][j+1], dp[i+1][j]);
          }
        }
        string ans;
        string curr="";
        bool flag=false;
        backtracking(ans,curr,dp,0,0,text1,text2,flag);
        return ans;
        }