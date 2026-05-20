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
int temp(TreeNode* root,TreeNode* subRoot){
    if(!root && !subRoot) return true;
    if(!root || !subRoot) return false;
    if(root->val != subRoot->val) return false;
    return temp(root->left, subRoot->left) && temp(root->right, subRoot->right);
}
bool fxn(TreeNode* root, TreeNode* subRoot){
    if(!root) return false;
    if(root->val==subRoot->val){
        if(temp(root,subRoot)) return true;
    }
    if(fxn(root->left,subRoot) || fxn(root->right,subRoot)) return true;
    return false;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       return fxn(root,subRoot);
    }
};