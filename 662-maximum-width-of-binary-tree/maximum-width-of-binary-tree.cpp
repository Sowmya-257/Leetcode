/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
         if (!root) return 0;

        unsigned long long maxWidth = 0; // use unsigned to match index types
        queue<pair<TreeNode*, unsigned long long>> q; // {node, index}
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = first;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                unsigned long long normIndex = index - first;
                last = index;

                if (node->left)
                    q.push({node->left, normIndex * 2 + 1});
                if (node->right)
                    q.push({node->right, normIndex * 2 + 2});
            }

            unsigned long long width = last - first + 1;
            maxWidth = max(maxWidth, width);
        }

        return static_cast<int>(maxWidth);
    }
};