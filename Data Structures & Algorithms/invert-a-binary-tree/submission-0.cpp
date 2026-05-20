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
void fxn(TreeNode* root){
    if(!root) return;
   fxn(root->left);
 fxn(root->right);
//     if(!root->left && !root->right) return ;
//     else if(!root->left){
// root->left=root->right;
// root->right=nullptr;
//     }
//     else if(!root->right){
// root->right=root->left;
// root->left=nullptr;
//     }
//     else{
// TreeNode* temp=root->right;
// root->right=root->left;
// root->left=temp;
//     }
TreeNode* temp=root->right;
root->right=root->left;
root->left=temp;
}
    TreeNode* invertTree(TreeNode* root) {
        fxn(root);
        return root;
    }
};
