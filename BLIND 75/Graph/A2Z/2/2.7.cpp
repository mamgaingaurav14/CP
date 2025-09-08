#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &visited){
        int m=board.size();
        int n=board[0].size();
       vector<pair<int,int>> directions={{0,-1},{-1,0},{1,0},{0,1}};
       for(auto it:directions){
        int x=i+it.first;
        int y=j+it.second;
        if(x<0 || y<0 || x>=m || y>=n  || visited[x][y]==1 || board[x][y]!='O') continue;
        visited[x][y]=1;
        dfs(x,y,board,visited);
       }
     }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int i=0;
        int j=0;
        vector<pair<int,int>> bounds;
            while(j<n-1){
                if(board[i][j]=='O') bounds.push_back({i,j});
                j++;
            }
            while(i<m-1){
                if(board[i][j]=='O') bounds.push_back({i,j});
                i++;
            }
            while(j>0){
                if(board[i][j]=='O') bounds.push_back({i,j});
                j--;
            }
            while(i>0){
                if(board[i][j]=='O') bounds.push_back({i,j});
                i--;
            }

        vector<vector<int>> visited(m,vector<int> (n,0));
        for(auto it:bounds){
            i=it.first;
            j=it.second;
            visited[i][j]=1;
            dfs(i,j,board,visited);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && visited[i][j]==0) board[i][j]='X';
            }
        }
    }
};
int main(){
    return 0;
}