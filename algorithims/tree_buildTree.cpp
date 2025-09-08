//HARE KRISHNA HARE KRISHNA
//KRISHNA KRISHNA HARE HARE
//HARE RAMA HARE RAMA
//RAMA RAMA HARE HARE


#include <bits/stdc++.h>
using namespace std;
#define lil long long int
const int MOD=1e9+7;

//tree strcuture
 struct TreeNode {
     int val;
     TreeNode*left;
     TreeNode*right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 
TreeNode* buildTreeFromVector(const vector<int>& values) {
    if (values.empty()) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Assign left child
        if (values[i] != -1) { // Use -1 to represent null nodes
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Assign right child
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}