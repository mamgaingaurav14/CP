//finding kth smallest element in a bst

//point is inorder traversal 
//is the sorted array in a bst

    int kthSmallest(TreeNode* root, int k) {
      vector<int> inorder;
      int count=0;
      helper(root,inorder,k,count);
      return inorder.back();
    }
    void helper(TreeNode* root,vector<int> &inorder,int &k,int &count){
        if(root==NULL) return;
        helper(root->left,inorder,k,count);
        if(count==k) return;
        count++;
        inorder.push_back(root->val);
        helper(root->right,inorder,k,count);
    }


    //
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     
    int kthSmallest(TreeNode* root, int k) {
      vector<int> inorder;
      helper(root,inorder);
      return inorder[k-1];
    }
    void helper(TreeNode* root,vector<int> &inorder){
        if(root==NULL) return;
        helper(root->left,inorder);
        inorder.push_back(root->val);
        helper(root->right,inorder);
    }
};
//
//without using extra space
    int kthSmallest(TreeNode* root, int k) {
      int count=0;
      int ans=0;
      helper(root,ans,k,count);
      return ans;
    }
    void helper(TreeNode* root,int &ans,int &k,int &count){
        if(root==NULL) return;
        helper(root->left,ans,k,count);
        count++;
        if(count==k){
          ans=(root->val);
          return;
        } 
        helper(root->right,ans,k,count);
    }