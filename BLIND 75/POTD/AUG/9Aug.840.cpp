   #include <bits/stdc++.h>
   using namespace std;
 class Solution {
public:
      

      //finally accepted code 
      
     bool check(int x,int y,vector<vector<int>>& grid){
        if(grid[x+1][y+1]!=5) return false;
        vector<int> curr_col={0,0,0};
        int left_diag=5+grid[x][y]+grid[x+2][y+2];
        int right_diag=5+grid[x][y+2]+grid[x+2][y];
        if(left_diag!=15 || right_diag!=15) return false;
        unordered_set<int> distinct;
        for(int i=x;i<=x+2;i++){
          int curr_row=0;
          for(int j=y;j<=y+2;j++){
            distinct.insert(grid[i][j]);
            if(grid[i][j]>9 || grid[i][j]<1 )  return false;
            curr_row+=grid[i][j];
            curr_col[j-y]+=grid[i][j];
          }
          if(curr_row!=15) return false;
        }
        if( distinct.size()!=9 || (curr_col[0]+curr_col[1])!=30 || curr_col[0]!=15) return false; 
        return true;
     }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m<3 || n<3) return 0;
        int cnt=0;
        int ans=0;
        int last=0;
        for(int i=0;i<m-2;i++){
          for(int j=0;j<n-2;j++){
           if(check(i,j,grid)){
            if(j>last+3) {
              cnt=1;
            }
            else{
              cnt++;
            }
             last=j;
           } 
           ans=max(ans,cnt);
           }
    }
     return ans;
    }
};
    int main(){
        return 0;
    }