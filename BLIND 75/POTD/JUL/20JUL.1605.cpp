//prpblem was solved
//easily using greedy approach 
//then later optimized 

 vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size();
        int n=colSum.size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(colSum[j]==0) continue;
              int a=min(rowSum[i],colSum[j]);
              rowSum[i]=rowSum[i]-a;
              colSum[j]=colSum[j]-a;
              ans[i][j]=a;
              if(rowSum[i]==0) break;
            }
        }
        return ans;
    }