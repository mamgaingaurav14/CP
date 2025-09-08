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
  
  
  //tree depth dfs
int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);
    }

//bfs tree depth 
   int maxDepth(TreeNode* root) {
       queue<TreeNode*> q;
       if(root==NULL) return 0;
       q.push(root);
       int level=0;
       while(!q.empty()){
          level++;
          int size=q.size();
          while(size--){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
          }
          
       }
       return level;
    }