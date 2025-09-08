//zigzag level order traversal
//just the previous code with new adaptations
 #define pb push_back
 #define sort(vec) sort(vec.begin(),vec.end())
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue <TreeNode*> nodes;
        if(root==NULL) return answer;
        nodes.push(root);
        bool flag=false;
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
            if(flag){
              reverse(level.begin(),level.end());
               flag=false; 
            }
            else flag=true;
            answer.push_back(level);
        }
        
        return answer;
    }