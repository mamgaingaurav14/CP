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
 
void recursion( map<int,map<int,multiset<int>>> &hash,TreeNode* root,int col,int row){
       if(root==NULL) return;
       hash[col][row].insert(root->val);
       recursion(hash,root->left,col-1,row+1);
       recursion(hash,root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> hash;
        recursion(hash,root,0,0);
        vector<vector<int>> answer;
        for(const auto it:hash){
            vector<int> vec;
           for(const auto &mp :it.second){
             vec.insert(vec.end(),mp.second.begin(),mp.second.end());
           } 
            answer.push_back(vec);
        }
        return answer;
    }

    //proper way of first sorting by rown
    //then if same row then sorting by vaues 
        void DFS_Traverse (TreeNode* a,int r,int c,map<int,map<int,multiset<int>>>&m )
    {
        if(!a) return;

        m[c][r].insert(a->val);
        DFS_Traverse(a->left,r+1,c-1,m);
        DFS_Traverse(a->right,r+1,c+1,m);
    }
    void BFS_Traverse(TreeNode* a ,map<int,map<int,multiset<int>>>& m )
    {
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({a,{0,0}});

        while(!q.empty())
        {
            auto x=q.front();q.pop();
            a=x.first;
            int r=x.second.first, c=x.second.second;

            m[c][r].insert(a->val);

            if(a->left)q.push({a->left,{r+1,c-1}});
            if(a->right)q.push({a->right,{r+1,c+1}});

        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* a) {
        vector<vector<int>> V;
        map<int,map<int,multiset<int>>> m ;
    
        // BFS_Traverse(a,m);
        DFS_Traverse(a,0,0,m);

        // Finally Push Into Vector !! 
        for(auto & col : m)
        {
            vector<int> v;
            for(auto & row : col.second)
                for(auto & val: row.second)
                    v.push_back(val);
            V.push_back(v);
        }

        return V;
    }

    int main(){
        return 0;
    }

    //letme try my way 
    void recursion( map<int,map<int,multiset<int>>> &hash,TreeNode* root,int col,int row){
       if(root==NULL) return;
       hash[col][row].insert(root->val);
       recursion(hash,root->left,col-1,row+1);
       recursion(hash,root->right,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> hash;
        recursion(hash,root,0,0);
        vector<vector<int>> answer;
        for(const auto it:hash){
           for(const auto &mp :it.second){
             vector<int> vec;
             vec.insert(vec.end(),mp.second.begin(),mp.second.end());
             answer.push_back(vec);
           } 
        }
        return answer;
    }