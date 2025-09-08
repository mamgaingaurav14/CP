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

  //but this is not optimized lets optimize this 
    vector<TreeNode* > leafNodes;
       TreeNode* findLCA(TreeNode* &root, TreeNode* &start,TreeNode* &end) {
        if(!root ||root==start|| root==end) return root;
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        if(left && right) return root;
        return left?left:right;
    }
       void recursion(TreeNode* &root){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            leafNodes.push_back(root);
            return ;
        }
        recursion(root->left);
        recursion(root->right);
       }
       void find_distance(TreeNode* &root,TreeNode* &start,TreeNode* &end,vector<int> &ans,int &distance){
          if(root==NULL) return;
          if(root==start || root==end){
            ans.push_back(distance);
            return ;
          } 
          distance++;
          find_distance(root->left,start,end,ans,distance);
          find_distance(root->right,start,end,ans,distance);
          distance--;
       }
    int countPairs(TreeNode* root, int distance) {
        recursion(root);
        int cnt=0;
        int n=leafNodes.size();
        for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            TreeNode* start=leafNodes[i];
            TreeNode* end=leafNodes[j];
            TreeNode* temp=findLCA(root,start,end);
            vector<int> ans;
            int dist=0;
            find_distance(temp,start,end,ans,dist);
            int leafsum=ans[0]+ans[1];
            if(leafsum<=distance) cnt++;
         }
        }
        return cnt;
    }

    //more opitmized but still tle 
      vector<TreeNode* > leafNodes;
       unordered_map<TreeNode*,int> depth;
       TreeNode* findLCA(TreeNode* &root, TreeNode* &start,TreeNode* &end) {
        if(!root ||root==start|| root==end) return root;
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        if(left && right) return root;
        return left?left:right;
    }
       void recursion(TreeNode* &root,int height){
        if(!root) return;
        depth[root]=height;
        if(root->left==NULL && root->right==NULL){
            leafNodes.push_back(root);
            return ;
        }
        recursion(root->left,height+1);
        recursion(root->right,height+1);
       }
    int countPairs(TreeNode* root, int distance) {
        recursion(root,0);
        int cnt=0;
        int n=leafNodes.size();
        for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            TreeNode* start=leafNodes[i];
            TreeNode* end=leafNodes[j];
            TreeNode* temp=findLCA(root,start,end);
            int leafsum=-2*depth[temp]+depth[start]+depth[end];
            if(leafsum<=distance) cnt++;
         }
        }
        return cnt;
    }
    //
//opotmized the lca function a lot here
    vector<TreeNode* > leafNodes;
       unordered_map<TreeNode*,int> depth;
       unordered_map<TreeNode*, TreeNode*> parent;

       TreeNode* findLCA(TreeNode* start,TreeNode* end) {
        if(depth[start]<depth[end]) swap(start,end);
        while(depth[start]>depth[end]){
            start=parent[start];
        }
        while(start!=end){
            start=parent[start];
            end=parent[end];
        }
        return start;
      }
       void recursion(TreeNode* &root,TreeNode* par,int height){
        if(!root) return;
        depth[root]=height;
        parent[root]=par;
        if(root->left==NULL && root->right==NULL){
            leafNodes.push_back(root);
            return ;
        }
        recursion(root->left,root,height+1);
        recursion(root->right,root,height+1);
       }
    int countPairs(TreeNode* root, int distance) {
   leafNodes.clear();
    depth.clear();
    parent.clear();
        recursion(root,NULL,0);
        int cnt=0;
        int n=leafNodes.size();
        for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            TreeNode* start=leafNodes[i];
            TreeNode* end=leafNodes[j];
            TreeNode* temp=findLCA(start,end);
            int leafsum=-2*depth[temp]+depth[start]+depth[end];
            if(leafsum<=distance) cnt++;
         }
        }
        return cnt;
    }
    int main(){
        return 0;
    }