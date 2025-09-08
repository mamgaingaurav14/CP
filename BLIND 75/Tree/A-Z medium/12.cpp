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
  bool recursion(TreeNode* lefti,TreeNode* righti){
        //base case
        if(lefti==NULL && righti==NULL) return true;
        if(lefti==NULL || righti==NULL || lefti->val!=righti->val) return false;
       return (recursion(lefti->left,righti->left) && recursion(lefti->right,righti->right));
    }
    bool isSymmetric(TreeNode* root) {
       return recursion(root->left,root->right);
    }
    int main(){
        return 0;
    }

