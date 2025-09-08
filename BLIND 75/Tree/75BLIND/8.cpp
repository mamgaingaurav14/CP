//construct unique tree from 
//inorder and postorder 
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

  //approach first but it involves militple times storing vectors
  //and is a enfficient approahch please optimize it further 

  //also you can use map data structure to directly search for the 
  //root element present in the inorder array instead of a  linear search 
  //everytime 
 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        if(n==0) return NULL;
        TreeNode* node=new TreeNode(postorder[n-1]);
        if(n==1) return node;
         // base case
         for(int j=0;j<n;j++){
           if(node->val==inorder[j]){
              vector<int> left_inorder(inorder.begin(),inorder.begin()+j);
              int size=left_inorder.size();
              vector<int> left_postorder(postorder.begin(),postorder.begin()+size);
              node->left=buildTree(left_inorder,left_postorder);

              vector<int> right_inorder(inorder.begin()+j+1,inorder.end());
              vector<int> right_postorder(postorder.begin()+size,postorder.end()-1);
              node->right=buildTree(right_inorder,right_postorder);
           }
         }
         return node;
        }
        int main(){
            return 0;
        }