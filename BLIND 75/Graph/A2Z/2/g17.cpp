#include <bits/stdc++.h>
using namespace std;
// another approach is understadning 
//that any graph with odd length cycle will not be 
//bipartite rest all be bipartite

/*

//dfs approach done 
	    bool dfs(int node,vector<int> adj[],vector<int> &visited, vector<int> &color){
	         //i wil travel node by 
	         for(int j:adj[node]){
                    if(visited[j]==1){
                        //already colored node hai 
                        if(color[j]==color[node]) return false;
                        else continue;
                    }
	                color[j]=!color[node];
	                visited[j]=1;
	                if(dfs(j,adj,visited,color)==false) return false;
	            }
	       
	        return true;
	     }
	        
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,0);
	    vector<int> visited(V,0);
	    //0==uncolor 1==first 2==second color
	    //bfs in all islands 
	    for(int i=0;i<V;i++){
	       if(visited[i]==1) continue;
	       visited[i]=1;
	       if(dfs(i,adj,visited,color)==false) return false;
	    }
	    return true;
	}
	*/

 bool bfs(int node,vector<vector<int>>& graph,vector<int> &color,vector<int> &visited){
      int m=graph.size();
      queue<int>  q;
      q.push({0});
      int last=1;
      while(!q.empty()){
        int size=q.size();
		int current=last?0:1;
        while(size--){
        int node=q.front();
        q.pop();
        if(color[node]!=-1 && color[node]!=current ) return false;
        color[node]=current;
        for(auto j:graph[node]){
          if(visited[j]==1) continue;
          q.push(j);
          visited[j]=1;
        }
      }
	  last=current;
     }
	 return true;
 }

    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<int> visited(m,0);
        vector<int> color(m,-1);
        for(int i=0;i<m;i++){
          if(visited[i]==1) continue;
          if(bfs(i,graph,color,visited)==false) return false;
        }
        return true;
    }
    int main(){
        return 0;
    }