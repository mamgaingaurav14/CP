#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 #define yes cout<<"YES"<<'\n';
 #define no cout<<"NO"<<'\n';


//one way O(2E) space complexities
 void undirected_graph(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    //vector<vector<int>> adj(n + 1); 
    int temp=m;
    while(temp--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 }

 //directed O(E) space complexities
  void directed_graph(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    //vector<vector<int>> adj(n + 1); 
    int temp=m;
    while(temp--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
 }

//weight matrix
  void directed_graph(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    //vector<vector<int>> adj(n + 1); 
    int temp=m;
    while(temp--){
        int u,v;
        cin>>u>>v;
        int weight=1;//default
        adj[u].push_back({v,weight});
    }
 }

 //components theory 
 //a graph can have various components
 //which can be connected as well disconnected 
 //for traversal array we should should visited array 
 //and this is how traversal with muitple 
 //components works 
 

 //bfs technique
 //two types of graph with 0 or 1 based indexing 
 //bfs is like level wise traversal
 //we need to traverl according tp levels
     vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        vector<int> answer;
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
                int element=q.front();
                answer.push_back(element);
                q.pop();
                for(int a:adj[element]){
                    if(visited[a]==0){
                      q.push(a);
                      visited[a]=1;
                    } 
                }
        }
        return answer;
     }
    //tc is o(N) +0(2E);
    //there is no need need while(size--)
    //since we are already eliminating all nodes traversed as 1 so thewy will not counted again 
  // Function to return a list containing the DFS traversal of the graph.
     void recursion(vector<int> &answer,vector<int> &visited,int node,vector<int> adj[]){
        answer.push_back(node);
        visited[node]=1;
        if(adj[node].empty()) return;
        for(int a:adj[node]){
           if(visited[a]==0) recursion(answer,visited,a,adj);
        }
    }
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        if(V==1) return {0};
        vector<int> answer;
        vector<int> visited(V,0);
        recursion(answer,visited,0,adj);
        return answer;
    }
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
       //solve;
       int n;
       cin>>n;
       
       vector<int> arr(n,0);
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
    }
}