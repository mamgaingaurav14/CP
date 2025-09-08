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

  //flawed method 1 since we will not be able to fully 
  //search in the tree
  /*
  TreeNode* search_val(int data,TreeNode *&root){
        if(!root) return NULL;
        if(root->val==data) return root;
        TreeNode* lefti=search_val(data,root->left);
        if(lefti) return lefti;
        TreeNode* righti=search_val(data,root->right);
        return righti;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root=NULL;
        
        for(auto it:descriptions){
           bool flag=false;
           int parent=it[0];
           int child=it[1];
           TreeNode* parent_node=search_val(parent,root);
           if(!parent_node) parent_node=new TreeNode(parent);
           TreeNode* child_node=search_val(child,root);
           if(!child_node) child_node=new TreeNode(child);
           else flag=true;
           if(it[2]) parent_node->left=child_node;
           else parent_node->right=child_node;
           if(flag) root=parent_node;
           if(!root) root=parent_node;
        }
        return root;
    }
    */
   //tree question finally solved 
     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode* > allnodes;
        unordered_set<TreeNode* > childnodes;
         for(auto arr:descriptions){
           int parent=arr[0];
           int child=arr[1];
           TreeNode* parent_node;
           if(allnodes.find(parent)!=allnodes.end()) parent_node=allnodes[parent];
            //parent already exist
           else{ parent_node= new TreeNode(parent);
             allnodes[parent]=parent_node;
           }

           TreeNode* child_node;
           if(allnodes.find(child)!=allnodes.end()) child_node=allnodes[child];
            //child already exist
            else{ child_node= new TreeNode(child);
             allnodes[child]=child_node;
            }
           childnodes.insert(child_node);
           if(arr[2]) parent_node->left=child_node;
           else parent_node->right=child_node;
        }
        for(auto it:allnodes){
            if(childnodes.find(it.second)==childnodes.end()) return it.second;
        }
        return NULL;
    }
   //more optimized using xor 
     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode* > allnodes;
        int prod=0;
         for(auto arr:descriptions){
           int parent=arr[0];
           int child=arr[1];
           TreeNode* parent_node;
           if(allnodes.find(parent)!=allnodes.end()) parent_node=allnodes[parent];
            //parent already exist
           else{ parent_node= new TreeNode(parent);
             allnodes[parent]=parent_node;
             prod=prod^parent;
           }
           TreeNode* child_node;
           if(allnodes.find(child)!=allnodes.end()) child_node=allnodes[child];
            //child already exist
            else{ child_node= new TreeNode(child);
             allnodes[child]=child_node;
             prod=prod^child;
            }
            prod=prod^child;
           if(arr[2]) parent_node->left=child_node;
           else parent_node->right=child_node;
        }
        return allnodes[prod];
    }
    int main(){
        return 1;
    }