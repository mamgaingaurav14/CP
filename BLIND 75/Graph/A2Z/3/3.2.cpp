//kahn's algorithim for topo sort

#include <bits/stdc++.h>
using namespace std;
 
 class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> indegree(V,0);
	   for(int i=0;i<V;i++){
	       for(int j:adj[i]){
	           indegree[j]++;
	       }
	   }
       vector<int> topo;
       queue<int> q;
       for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
       }
       while(!q.empty()){
	      int node=q.front();
          topo.push_back(node);
          q.pop();
          for(int j:adj[node]){
            indegree[j]--;
            if(indegree[j]==0) q.push(j);
          }
       }
	    // code here
        return topo;
	}
};
 int main(){

 }