class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        // Iterative inorder traversal
        while (curr || !st.empty()) {
            // Go to the leftmost node
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();
            k--; // decrement k when visiting a node

            if (k == 0) return curr->val; // kth smallest found

            // Go to the right subtree
            curr = curr->right;
        }
        return -1; // should not happen if k is valid
    }
};
