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
  /*
  string recursion_start(TreeNode* root, int start,string tostart){
      if(root==NULL) return "-1";
      if(root->val==start) return tostart;
      tostart+="U";
      string lefti=recursion_start(root->left,start,tostart);
      string righti=recursion_start(root->right,start,tostart);
      if(lefti=="-1") return righti;
      if(righti=="-1") return lefti;
      return "-1";
    }
     string recursion_end(TreeNode* root, int end,string toend){
      if(root==NULL) return "-1";
      if(root->val==end) return toend;
      string lefti=recursion_end(root->left,end,toend+"L");
      string righti=recursion_end(root->right,end,toend+"R");
      if(lefti=="-1") return righti;
      if(righti=="-1") return lefti;
      return "-1";
    }
    string maker(TreeNode* root, int start, int end){
        string tostart=recursion_start(root,start,"");
        string toend=recursion_end(root,end,"");
        if(tostart=="-1"||toend=="-1") return "-1";
        return tostart+toend;
    }
   
    void solve(TreeNode* root, int start, int end,string &answer){
        if(root==NULL) return;
        int n=answer.size();
        if(answer=="-1") n=INT_MAX;
        string fromthisroot=maker(root,start,end);
        int m=fromthisroot.size();
        if(m<n && fromthisroot!="-1") answer=fromthisroot;
        solve(root->left,start,end,answer);
        solve(root->right,start,end,answer);
    }
    string getDirections(TreeNode* root, int start, int end) {
        string answer="-1";
        solve(root,start,end,answer);
        return answer;
    }
    int main(){
        return 0;
    }

    //method new lca 
      TreeNode* findLCA(TreeNode* root, int start, int end) {
        if(!root ||root->val==start|| root->val==end) return root;
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        if(left && right) return root;
        return left?left:right;
    }
     string getDirections(TreeNode* root, int start, int end) {
        return maker(findLCA(root,start,end),start,end);
    }

    */
   void recursion_start(TreeNode* root, int &start,string &tostart,string &anstart){
      if(root==NULL) return ;
      if(root->val==start){
        anstart=tostart;
        return ;
      } 
      tostart+="U";
      recursion_start(root->left,start,tostart,anstart);
      recursion_start(root->right,start,tostart,anstart);
      tostart.erase(tostart.end());
    }
     void recursion_end(TreeNode* &root, int &end,string &toend,string &ansend){
      if(root==NULL) return;
      if(root->val==end){
        ansend=toend;
        return;
      }
      toend=toend+"L";
      recursion_end(root->left,end,toend,ansend);
      toend.erase(toend.end());
      toend=toend+"R";
      recursion_end(root->right,end,toend,ansend);
      toend.erase(toend.end());
    }
    string maker(TreeNode* root, int &start, int &end){
        string tostart="";
        string anstart="";
        string toend="";
        string ansend="";
        recursion_start(root,start,tostart,anstart);
        recursion_end(root,end,toend,ansend);
        return tostart+toend;
    }
     TreeNode* findLCA(TreeNode* root, int &start, int &end) {
        if(!root ||root->val==start|| root->val==end) return root;
        TreeNode* left = findLCA(root->left, start, end);
        TreeNode* right = findLCA(root->right, start, end);
        if(left && right) return root;
        return left?left:right;
    }
    string getDirections(TreeNode* root, int start,int end) {
        return maker(findLCA(root,start,end),start,end);
    }
    int main(){
        return 1;
    }
