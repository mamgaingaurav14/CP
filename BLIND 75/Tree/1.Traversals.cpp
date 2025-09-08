#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;
#define pb push_back

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//recursive traversals
void preorder(TreeNode* root,vector<int> &answer){
      if(root==NULL) return;
      answer.pb(root->val);
      solve(root->left,answer);
      solve(root->right,answer);
    }
void inorder(TreeNode* root,vector<int> &answer){
      if(root==NULL) return;
      inorder(root->left,answer);
      answer.push_back(root->val);
      inorder(root->right,answer);
    }

 void postorder(TreeNode* root,vector<int> &answer){
      if(root==NULL) return;
      postorder(root->left,answer);
      postorder(root->right,answer);
      answer.push_back(root->val);
    }
//LEVEL ORDER TRaversal
// i was trying dfs actually which i didnt knew
//wrong method sinc you dont know the actual lenght of breadth of answer ,but you can temporary make space
//by using answer.emplace_back();
//this is basically depth first technique keeping track of indices 
   void levelorder_DFS(TreeNode* root,vector<vector<int>> &answer,int index){
       if(root==NULL) return;
       if(index>=answer.size()) answer.emplace_back();//you are making an empty place here
       //if(index>=answer.size()) answer.push_back({});//you are making an empty place here
       answer[index].push_back(root->val);
       levelorder_DFS(root->left,answer,index+1);
       levelorder_DFS(root->right,answer,index+1);
     }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;//here answer size is zero
        int index=0;
        levelorder_DFS(root,answer,index);
        return answer;
    }

//queue method 

//this method is very important 
   vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue <TreeNode*> nodes;
        if(root==NULL) return answer;
        nodes.push(root);
        while(!nodes.empty()){
            vector<int> level;
            int size=nodes.size();
            while(size--){
            TreeNode* current=nodes.front();
            level.push_back(current->val);
          if(current->left) nodes.push(current->left);
          if(current->right) nodes.push(current->right);
             nodes.pop();
            }
            answer.push_back(level);
        }
        return answer;
    }
    //ITERATIVE TRAVERSALS
  vector<int> preorderTraversal_iterative(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> answer;
       if(root) st.push(root);
        while(!st.empty()){
        TreeNode* temp=st.top();
          if(temp->right) st.push(temp->right);
          if(temp->left)  st.push(temp->left);
          answer.push_back(temp->val);
          st.pop();
        }
        return answer;
    }

     vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> answer;
       if(root) st.push(root);
        while(!st.empty()){
        TreeNode* temp=st.top();
          answer.push_back(temp->val);
          st.pop();
          if(temp->right) st.push(temp->right);
          if(temp->left)  st.push(temp->left);
         
        }
        return answer;
    }

     vector<int> inorderTraversal_iterative(TreeNode* root) {
        stack <TreeNode*> st;
        vector<int> answer;
        TreeNode* node=root;
        while(true){
           if(node!=NULL){
            st.push(node);
            node=node->left;
           }
           else{
            //ab mera node null bn gya 
            if(st.empty()==true) break;
            node=st.top();
            st.pop();
            answer.push_back(node->val);
            node=node->right;
           }
            
        }
        return answer;
    }

//learnt two codes which are enough 
//not interested in any more code
//post order one way using preorder method only just right ka left bna do then at last reverse the vector array 
       vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> answer;
       if(root) st.push(root);
        while(!st.empty()){
        TreeNode* temp=st.top();
          answer.push_back(temp->val);
          st.pop();
          if(temp->left)  st.push(temp->left);
          if(temp->right) st.push(temp->right);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }


//one code for all //dont do this just watch striver
   void check_hash( unordered_map<TreeNode*,int> &hash,TreeNode* node, vector<int> &pre,
   vector<int> &in,vector<int> &post){
          hash[node]++;
          if(hash[node]==1) pre.push_back(node->val);
          if(hash[node]==2) in.push_back(node->val);
          if(hash[node]==3) post.push_back(node->val);
   }
 vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
         vector<int> pre;
         vector<int> in;
         vector<int> post;
       TreeNode* node=root;
       unordered_map<TreeNode*,int> hash;
       while(1){
         check_hash(hash,node,pre,in,post);
          if(node->left){
            st.push(node);
            TreeNode* temp=node->left;
            node->left=NULL;
            node=temp;
            continue;
          }
          check_hash(hash,node,pre,in,post);
          if(node->right){
            //passing it second time
            st.push(node);
            TreeNode* temp=node->right;
            node->right=NULL;
            node=temp;
            continue;
          }
          check_hash(hash,node,pre,in,post);
            if(!st.empty()) break;
            node=st.top();
            st.pop();
          
       }
    }

    //striver bhai
//this code is nearly same as mine but i couldnt figure the some things
//this is the code you need to learn to 
     vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
         vector<int> pre,in,post;
         if(root==NULL) return ;
         st.push({root,1});       TreeNode* node=root;
      while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
          pre.push_back(it.first->val);
          it.second++;
          st.push(it);
          if(it.first->left) st.push({it.first->left,1});
        }
        else if (it.second==2){
          in.push_back(it.first->val);
          it.second++;
          st.push(it);
          if(it.first->right) st.push({it.first->right,1});
        }
        else{
          post.push_back(it.first->val);
        }
      }
      return post;
    }