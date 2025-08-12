
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;

        // Current node must be strictly between minVal and maxVal
        if (node->val <= minVal || node->val >= maxVal) 
            return false;

        // Left subtree: max value changes
        // Right subtree: min value changes
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};