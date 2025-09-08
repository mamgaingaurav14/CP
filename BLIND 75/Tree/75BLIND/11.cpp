 
 //without using bst knowledge 
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;
        return left?left:right;
    }
//simple ez pz

//after using bst knowledge 

//using bst logic of elimiaitng note if less than or equal to 
//current node
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(p->val<q->val) swap(p,q);
        if(root->val<=p->val && root->val>=q->val) return root;
        else if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);
    }