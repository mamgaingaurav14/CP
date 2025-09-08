//checking height is balanced or not 
//using the prev apprach only 

class solution{
    public:

  unordered_map <TreeNode*,int> hash;
     int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(hash.find(root)!=hash.end()) return hash[root];
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return hash[root]=1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
       if(!root) return true;
       if(abs(maxDepth(root->left) - maxDepth(root->right))>1){
          return false;
        }
       return (isBalanced(root->left) && isBalanced(root->right));
    }
};