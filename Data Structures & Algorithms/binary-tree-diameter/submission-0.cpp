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

    int height(TreeNode* root){
        if(!root) return 0;
        int left = 1 + height(root->left);
        int right = 1 + height(root->right);
        return max(left, right);
    }
    int fxn(TreeNode* root){
        if(!root) return 0;
        int leftdia = fxn(root->left);
        int rightdia = fxn(root->right);
        int left = height(root->left);
        int right = height(root->right);

        return max(left + right, max(leftdia, rightdia));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return fxn(root);
    }
};