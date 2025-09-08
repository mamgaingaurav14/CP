//checking a bst or not 
  #include <bits/stdc++.h>
 //check subtree or not
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

bool isValidBST(TreeNode* root) {
        return helperBST(root,LLONG_MAX,LLONG_MIN);
    }
    bool helperBST(TreeNode* root,long long int maxi,long long int mini){
        if(root==NULL) return true;
        if(root->val>= maxi || root->val<=mini) return false;
        return ( helperBST(root->left,root->val,mini) && helperBST(root->right,maxi,root->val ));
    }