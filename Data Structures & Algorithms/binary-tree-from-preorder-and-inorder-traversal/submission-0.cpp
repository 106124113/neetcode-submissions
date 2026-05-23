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
TreeNode* fxn(vector<int>& preorder, vector<int>& inorder,int prestart,int preend,int instart,int inend,map<int,int>mp,int n){
  if(prestart>preend || instart>inend) return nullptr;
    TreeNode* root=new TreeNode(preorder[prestart]);
    int i=mp[preorder[prestart]];
root->left=fxn(preorder,inorder,prestart+1,prestart+i-instart,instart,i-1,mp,n);
root->right=fxn(preorder,inorder,prestart+i-instart+1,preend,i+1,inend,mp,n);
return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // TreeNode* root=nullptr;
        int n=preorder.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
      return  fxn(preorder,inorder,0,n-1,0,n-1,mp,n-1);
    }
};
