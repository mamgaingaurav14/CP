#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

     void dfs(int i,int j,vector<vector<int>> &grid, vector<vector<int>> &visited){
        int m=grid.size();
        int n=grid[0].size();
        visited[i][j]=1;
       vector<pair<int,int> >directions={{0,1},{1,0},{-1,0},{0,-1}};
       for(auto it:directions){
        int x=i+it.first;
        int y=j+it.second;
        if(x<0 || y<0 || x>m || y>n || visited[x][y]==1 || grid[x][y]==0) continue;
        dfs(x,y,grid,visited);
       }
     }
    bool dis(vector<vector<int>>& grid, vector<vector<int>> &visited){
        int m=grid.size();
        int n=grid[0].size();
        bool mila=false;
        int i=0,j=0;
        for(;i<m;i++){
            for(;j<n;j++){
              if(grid[i][j]!=1) continue;
              mila=true;
              break;
            }
        }
        if(!mila) return true;
        dfs(i,j,grid,visited);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]==1 && visited[i][j]==0) return true;
            }
        }
        return false;
    }
    bool con(vector<vector<int>>& grid, vector<vector<int>> &visited){
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(visited[i][j]!=1) continue;
              vector<vector<int>> hello(m,vector<int> (n,0));
              visited[i][j]=0;
              if(dis(visited,hello)) return true;
              visited[i][j]=1;
            }
        } 
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        if(dis(grid,visited)) return 0;
        else if (con(grid,visited)) return 1;
        else return 2;
    }
};
int main(){
    return 0;
}