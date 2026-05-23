class Solution {
public:
bool fxn(TreeNode* root,long long minval,long long maxval){
    if(!root) return true;

    if(root->val <= minval || root->val >= maxval)
        return false;

    return fxn(root->left,minval,root->val) &&
           fxn(root->right,root->val,maxval);
}

    bool isValidBST(TreeNode* root) {
         return fxn(root,LLONG_MIN,LLONG_MAX);
    }
};
