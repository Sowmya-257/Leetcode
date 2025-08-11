class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if (!root) return new TreeNode(val); // Empty spot found, insert here
        
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        
        return root; 
    }
};