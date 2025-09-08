//right/left view 
vector<int> rightSideView(TreeNode* root) {
       vector<int> answer;
       queue<TreeNode*> q;
       if(root==NULL) return answer;
       q.push(root);
       while(!q.empty()){
          int size=q.size();
          int copysize=size;
          while(size--){
            TreeNode* temp=q.front();
            q.pop();
            if(copysize-1==size)  answer.push_back(temp->val);
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
          }
          
       }
       return answer;
    }