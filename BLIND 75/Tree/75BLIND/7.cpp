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

 bool isTreeSame(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL || root1->val!=root2->val) return false;
        return  (isTreeSame(root1->left,root2->left) && isTreeSame(root1->right,root2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if ((root==NULL && subRoot==NULL) || ( isTreeSame(root,subRoot)) )return true; 
        if(root==NULL || subRoot==NULL ) return false;
        return ( isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) ); 
    }
    int main(){

    }
