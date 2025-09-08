class Solution {
public:
    void recursion(vector<int> &visited,vector<vector<int>>& isConnected,int node){
          visited[node]=1;
          int m=isConnected.size();
          for(int j=0;j<m;j++){
            if(visited[j]==0 && isConnected[node][j]==1) recursion(visited,isConnected,j);
          }
       }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        vector<int> visited(m,0);
        int cnt=0;
        for(int i=0;i<m;i++){
            if(visited[i]==1) continue;
            cnt++;
            recursion(visited,isConnected,i);
        }
        return cnt;
    }
};
//approach was simple using a visted array 
//for marking the viisted nodes 