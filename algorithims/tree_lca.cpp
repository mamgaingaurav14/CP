#include <bits/stdc++.h>
using namespace std;
//functions for CP

//tree strcuture
 struct TreeNode {
     int val;
     TreeNode*left;
     TreeNode*right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
  TreeNode* findLCA(TreeNode* root, int start, int end) {
        if(!root ||root->val==start|| root->val==end) return root;
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        if(left && right) return root;
        return left?left:right;
    }