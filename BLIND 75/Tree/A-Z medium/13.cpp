 #include <bits/stdc++.h>
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

  //wrong answer due to scope issue
void solve(TreeNode* lefti,TreeNode* righti){
      if(lefti==NULL && righti==NULL) return;
      TreeNode* temp=lefti;
      lefti=righti;
      righti=temp;
      if(lefti) solve(lefti->left,lefti->right);
      if(righti) solve(righti->left,righti->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        solve(root->left,root->right);
        return root; 
    }


//bit this is right duh 
 void solve(TreeNode* root){
      if(root==NULL) return;
      TreeNode* temp=root->left;
      root->left=root->right;
      root->right=temp;
       solve(root->left);
       solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }


    //
//if you arr sending * root then that means 
/*you are eventually making a copy of the orginal arddress though that have all
other inside addresses same copy of copy
after putting an and we will send the orginal addresses duh

//af
*/
//this is also right 
void solve(TreeNode* &lefti,TreeNode* &righti){
      if(lefti==NULL && righti==NULL) return;
      TreeNode* temp=lefti;
      lefti=righti;
      righti=temp;
      if(lefti) solve(lefti->left,lefti->right);
      if(righti) solve(righti->left,righti->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        solve(root->left,root->right);
        return root; 
    }
