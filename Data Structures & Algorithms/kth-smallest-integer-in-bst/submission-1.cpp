class Solution {
public:

int fxn(TreeNode* root, int k, vector<int>& vec){

    if(!root) return -1;

    if(vec.size()==k) return vec[vec.size()-1];

    int left = fxn(root->left,k,vec);

    if(left!=-1) return left;

    vec.push_back(root->val);

    if(vec.size()==k) return root->val;

    return fxn(root->right,k,vec);
}

    int kthSmallest(TreeNode* root, int k) {

        vector<int> vec;

        return fxn(root,k,vec);
    }
};
