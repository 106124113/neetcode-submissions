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
TreeNode* fxn(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root->val>=p->val && root->val<=q->val) return root;
   else if(root->val<p->val) return fxn(root->right,p,q);
    else return fxn(root->left,p,q);
    // return root;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val) return fxn(root,p,q);
        else return fxn(root,q,p);
    }
};
