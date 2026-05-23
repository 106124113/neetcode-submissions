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

class Codec {
public:

    string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* x = q.front();
            q.pop();

            if (x == nullptr) {
                s += "#,";
                continue;
            }

            s += to_string(x->val);
            s += ",";

            q.push(x->left);
            q.push(x->right);
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');

        if (str == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // left
            getline(ss, str, ',');
            if (str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // right
            getline(ss, str, ',');
            if (str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};
