#include <bits/stdc++.h>
using namespace std;
 void recursion(vector<vector<int>> &visited,int &cnt,vector<vector<int>>& grid,int i, int j){
        visited[i][j]=1;
        int m=grid.size();
        int n=grid[0].size();
        if(i+1<m && grid[i+1][j]!=0) recursion(visited,cnt,grid,i,j);
        if(j+1<n && grid[i][j+1]!=0) recursion(visited,cnt,grid,i,j);
        if(i-1>=0 && grid[i-1][j]!=0) recursion(visited,cnt,grid,i,j);
        if(j-1>=0 && grid[i][j-1]!=0) recursion(visited,cnt,grid,i,j);
     }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans;
        vector<vector<int>> visited(m,vector<int> (n,0));
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]==2 && visited[i][j]==0){
                int cnt=0
                //rotten hai yeh
                //call or all connected rottens 
                recursion(visited,cnt,grid,i,j);
                maxi=max(maxi,cnt);
              }
            }
        
int main(){

}