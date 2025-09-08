//max path sum 


//similar to previous questions only 

//this took some time but th point here was 
//we need to return the maximum path that point 
//no the global mhttps://www.codechef.com/practiceaxi path sum 

int maxi=INT_MIN;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int left=max(0,helper(root->left));
        int right=max(0,helper(root->right));
        maxi=max(maxi,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxi;
    }