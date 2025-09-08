 #include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
 #define pb push_back
 //we did the problem and we learny a new thing 
// where we need to declare the funtion declaration
//before in order to use them 
 #define sort(vec) sort(vec.begin(),vec.end())
 struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
  // Function declarations
bool binary_search(int target, vector<int>& arr);
void solve(TreeNode* root, vector<int>& to_delete);
void recursion(TreeNode* root, vector<int>& to_delete);
vector<TreeNode*> answer;

      bool binary_search(int target,vector<int> &arr){
    int i=0;
    int j=arr.size()-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target){
          i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return false;
       }
    void recursion(TreeNode* root,vector<int>& to_delete){
        if(!root) return;
        if(binary_search(root->val,to_delete)){
        recursion(root->left,to_delete);
        recursion(root->right,to_delete);
       }
       else{
         answer.push_back(root);
         solve(root,to_delete);
       }
    }
    void solve(TreeNode* root, vector<int>& to_delete){
       if(!root) return;
       if(root->left && binary_search(root->left->val,to_delete)){
        recursion(root->left->left,to_delete);
        recursion(root->left->right,to_delete);
        root->left=NULL;
       }
       else{
        solve(root->left,to_delete);
       }
       if(root->right && binary_search(root->right->val,to_delete)){
        recursion(root->right->left,to_delete);
        recursion(root->right->right,to_delete);
        root->right=NULL;
       }
       else{
         solve(root->right,to_delete);
       }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       sort(to_delete);
       recursion(root,to_delete);
       return answer;
    }
    int main(){
        return 0;
    }