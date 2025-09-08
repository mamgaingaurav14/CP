//topo sort
//approach is simple first check whether there exost a ccyle in 
//directed grapgh or not ..then find the order 
# include <bits/stdc++.h>
 using namespace std;

class Solution {
public:
     bool dfs(int i,vector<int> adj[],vector<int> & vis, vector<int> & path_vis){
      for(int j:adj[i]){
        if(vis[j]==1 ){
          if( path_vis[j]==1 ) return true;
          else continue;
        }
        path_vis[j]=1;
        vis[j]=1;
        if( dfs(j,adj,vis,path_vis)) return true;
        path_vis[j]=0;
      }
      return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path_vis(V,0);
        for(int i=0;i<V;i++){
        if(vis[i]!=0) continue;
         vis[i]=1;
         path_vis[i]=1;
         if( dfs(i,adj,vis,path_vis)) return true;
         path_vis[i]=0;
        }
        return false;
    }


    void DFS(int node,vector<int> & visited , vector<int> adj[],  vector<int> &answer){
     visited[node]=1;
     for(auto i:adj[node]){
        if(visited[i]) continue;
        DFS(i,visited,adj,answer);
      }
      answer.push_back(node);
    }
    vector<int> findOrder(int V, vector<vector<int>>& arr) {
       vector<int> adj[V];
       for(auto it:arr){
        int first=it[0];
        int second=it[1];
        adj[first].push_back(second);
       }
       vector<int> answer;
       if(isCyclic(V,adj)) return answer;
       vector<int> visited(V,0);
       
       for(int i=0;i<V;i++){
        if(visited[i]) continue;
        DFS(i,visited,adj,answer);
       }
      return answer;
    }
};


//easier way buddy light weight 
  void dfs(int node,vector<vector<int>>& adj,vector<int> & ans,vector<int> & vis){
        if(vis[node]) return;
        vis[node]=1;
        for(auto it:adj[node]){
            dfs(it,adj,ans,vis);
        }
        ans.push_back(node);
     }
    
vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            dfs(i,adj,ans,vis);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
  int main(){

  }


  //
  