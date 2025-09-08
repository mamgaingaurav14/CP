#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 #define yes cout<<"YES"<<'\n';
 #define no cout<<"NO"<<'\n';

void dfs(int i,int j,vector<vector<int>>& board,vector<vector<int>> &visited){
        int m=board.size();
        int n=board[0].size();
       vector<pair<int,int>> directions={{0,-1},{-1,0},{1,0},{0,1}};
       for(auto it:directions){
        int x=i+it.first;
        int y=j+it.second;
        if(x<0 || y<0 || x>=m || y>=n  || visited[x][y]==1|| board[x][y]==0) continue;
        visited[x][y]=1;
        dfs(x,y,board,visited);
       }
     }

void bfs(int i,int j,vector<vector<int>>& board,vector<vector<int>> &visited){
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
       vector<pair<int,int>> directions={{0,-1},{-1,0},{1,0},{0,1}};
    while(!q.empty()){
     i=q.front().first;
     j=q.front().second;
     q.pop();
       for(auto it:directions){
        int x=i+it.first;
        int y=j+it.second;
        if(x<0 || y<0 || x>=m || y>=n  || visited[x][y]==1|| board[x][y]==0) continue;
        visited[x][y]=1;
        q.push({x,y});
       }
     }
}

        int numEnclaves(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        int i=0;
        int j=0;
        vector<pair<int,int>> bounds;
        if(m==n==1){
          if(board[i][j]==1) bounds.push_back({i,j});  
        }
            while(j<n-1){
                if(board[i][j]==1) bounds.push_back({i,j});
                j++;
            }
            while(i<m-1){
                if(board[i][j]==1) bounds.push_back({i,j});
                i++;
            }
            while(j>0){
                if(board[i][j]==1) bounds.push_back({i,j});
                j--;
            }
            while(i>0){
                if(board[i][j]==1) bounds.push_back({i,j});
                i--;
            }

        vector<vector<int>> visited(m,vector<int> (n,0));
        for(auto it:bounds){
            i=it.first;
            j=it.second;
            visited[i][j]=1;
            bfs(i,j,board,visited);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1 && visited[i][j]==0) cnt++;
            }
        }
        return cnt;
    }

int main(){
    return 0;
}
