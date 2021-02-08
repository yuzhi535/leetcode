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
    bool isBalanced(TreeNode* root) {
        if (nullptr == root)
            return true;
        int l = height(root->left), r = height(root->right);
        if (std::abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        } else {
            return false;
        }
    }

    int height(TreeNode* root) {
        if (root) {
            return 1 + std::max(height(root->left), height(root->right));
        } else {
            return 0;
        }
    }
};