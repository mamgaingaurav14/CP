 #include <bits/stdc++.h>
 //check subtree or not
 //stringstream and getline using
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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
          int size=q.size();
          while(size--){
            TreeNode* temp=q.front();
            q.pop();
            if(!temp){
                ans+="#,";
            }
            else{
                ans+=to_string(temp->val) +",";
                q.push(temp->left);
                q.push(temp->right);
            }
          }
        }
      return ans;
    }
    int helper(string &data,int &index){
      if(data[index]=='#') {
        index+=2;
        return 2000;
        }
        int n=data.size();
        int i=index;
        for(;i<n;i++){
          if(data[i]==',') break;
          }
        string temp=data.substr(index,i-index);
        index=i+1;
        return stoi(temp);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       int n=data.size();
       if(!n) return NULL;
       int index=0;
       TreeNode* root=new TreeNode(helper(data,index));
       queue <TreeNode* > q;
       q.push(root);
        while(!q.empty()){
          int size=q.size();
          while(size--){
            TreeNode* temp=q.front();
            q.pop(); 
            int left=helper(data,index);
            if(left==2000){
                temp->left=NULL;
            }
            else{
                TreeNode* temp_left=new TreeNode(left);
                temp->left=temp_left;
                q.push(temp_left);
            }
            int right=helper(data,index);
            if(right==2000){
                temp->right=NULL;
            }
            else{
                TreeNode* temp_right=new TreeNode(right);
                temp->right=temp_right;
                q.push(temp_right);
            }
          }
        }
       return root;
       }