//height of binary tree


//basic recursion  method 1
   int solve(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int left=1,right=1;
        if(root->left) left=1+solve(root->left);
        if(root->right) right=1+solve(root->right);
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }

    //4 line code
    //basic recursion  method 2
      int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);
    }


//bfs approach 
  //using bfs approach 
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