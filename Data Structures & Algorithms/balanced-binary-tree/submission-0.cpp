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
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}
bool fxn(TreeNode* root){
    if(!root) return true;
int lefth=height(root->left);
int righth=height(root->right);
if(abs(lefth-righth)>1) return false;
if(!fxn(root->left) || !fxn(root->right)) return false;
return true;
}
    bool isBalanced(TreeNode* root) {
        return fxn(root);
    }
};
