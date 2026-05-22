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
int fxn(TreeNode* root,int maxval){
    if(!root) return 0;
    int res=0;
    if(root->val>=maxval) res=1;
    maxval=max(maxval,root->val);
   res+= fxn(root->left,maxval);
   res+= fxn(root->right,maxval);
return res;
}
    int goodNodes(TreeNode* root) {
     return fxn(root,root->val);  
    }
};
