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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<vector<int>>vec;
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int k=q.front().second;
            q.pop();
            if(vec.size() == k)
                vec.push_back({});
     vec[k].push_back(temp->val);
  if(temp->left) q.push({temp->left,k+1});
  if(temp->right) q.push({temp->right,k+1});
        }
        return vec;
    }
};
