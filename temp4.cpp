
#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
       TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
  };



unordered_map<TreeNode* ,bool> pp,qq;

  bool find_p(TreeNode* node,TreeNode* p){
    if(node==NULL) return false;
    if(node==p) return pp[node]=true;
    return pp[node]=find_p(node->left,p)||find_p(node->right,p);
  }
  bool find_q(TreeNode* node,TreeNode* q){
    if(node==NULL) return false;
    if(node==q) return qq[node]=true;
    return qq[node]=find_q(node->left,q)||find_q(node->right,q);
  }
  TreeNode* dfs(TreeNode* root){
    if(!root) return NULL;
    if(pp[root->left] && qq[root->right]) return root;
    if(dfs(root->left)) return dfs(root->left);
    return dfs(root->right);
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_p(root,p); find_q(root,q);
        return dfs(root);
    }

    int main(){
      #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    
   
    }
