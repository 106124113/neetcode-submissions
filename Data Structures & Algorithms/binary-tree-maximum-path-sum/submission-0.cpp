class Solution {
public:
int fxn(TreeNode* root,int &maxi){
    if(!root) return 0;
    int left=fxn(root->left,maxi);
    int right=fxn(root->right,maxi);
  if(left>0 && right>0) maxi=max(maxi,root->val+left+right);
  else if(left>0) maxi=max(maxi,root->val+left);
  else if(right>0) maxi=max(maxi,root->val+right);
  else maxi=max(maxi,root->val);
    return max(max(left,right)+root->val,root->val);
}
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
         fxn(root,maxi);
         return maxi;
    }
};