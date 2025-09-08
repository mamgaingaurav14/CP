
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