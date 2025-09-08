 #include <bits/stdc++.h>
 using namespace std;
 //tree strcuture
 struct TreeNode {
     int val;
     TreeNode*left;
     TreeNode*right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
 //diametere of tree 
   void dfs(int node,vector<vector<int>>& adj,int parent,int val,int &ans,int &end_node){
        if(val>ans){
            ans=val;
            end_node=node;
        }
         for(int child:adj[node]){
            if(child==parent) continue;
            dfs(child,adj,node,val+1,ans,end_node);
         }
    }

    int get_max(vector<vector<int>>& adj){
      int n=adj.size();
      int ans=0,end_node=0;
       dfs(0,adj,-1,0,ans,end_node);
       ans=0;
       dfs(end_node,adj,-1,0,ans,end_node);
      return ans;
    }