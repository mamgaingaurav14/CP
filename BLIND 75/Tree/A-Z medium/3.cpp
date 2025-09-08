//diamter question 
//here we re applied the prev question logic only 
//mulitple times 

 unordered_map <TreeNode*,int> hash;
     int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(hash.find(root)!=hash.end()) return hash[root];
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return hash[root]=1+max(left,right);
    }
   
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int current= maxDepth(root->left) + maxDepth(root->right);
        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);
        return max( max(left,right),current);
    }