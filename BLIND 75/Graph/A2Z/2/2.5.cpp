#include <bits/stdc++.h>
using namespace std;

//detecting a cycle is tricky 
//its like finding a node which is already visited 
//but not came from a cycle 
//for dicsonccetd graphs we have to call only for parts graph 
//is disconnected not all points 
//this is the approach 

//bfs appraoach
bool bfs_check(int x,vector<int> adj[],vector<int> &visited){
        queue<pair<int,int>> q;
        q.push({x,-1});
        while(!q.empty()){
            int node=q.front().first;
            int prev=q.front().second;
            q.pop();
            if(visited[node]==1) return true;
            visited[node]=1;
            for(int x:adj[node]){
                if(x!=prev) q.push({x,node});
            }
        }
        return false;
    }
//dfs approach 
//logic remains the same 
    bool dfs_check(int x,vector<int> adj[],vector<int> &visited,int prev){
        if(visited[x]) return true;
        visited[x]=1;
        for(int y:adj[x]){
            if(y!=prev && dfs_check(y,adj,visited,x)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        //Code here
        //bfs way 
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==1) continue;
            if(dfs_check(i,adj,visited)) return true;
        }
        return false;
    }
    int main(){
        return 0;
    }