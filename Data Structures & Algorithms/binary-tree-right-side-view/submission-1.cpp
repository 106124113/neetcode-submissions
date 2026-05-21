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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int a=q.front().second;
            q.pop();
           if(ans.size()==a) ans.push_back(temp->val);
           if(temp->right) q.push({temp->right,a+1});
           if(temp->left) q.push({temp->left,a+1});
        }
        return ans;
    }
};
