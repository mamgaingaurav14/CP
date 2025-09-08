//check if two
// trees are same or not 
//very easy with recursion
//using recursion in tree is important
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((p==NULL || q==NULL) || (p->val)!=(q->val)) return false;
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }