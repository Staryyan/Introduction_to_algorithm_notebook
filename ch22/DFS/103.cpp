/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) { return {}; }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool even = false;
        vector<vector<int>> ans;
        while (!nodeQueue.empty()) {
            vector<int> cur;
            int _size = nodeQueue.size();
            for (int i = 0; i < _size; ++i) {
                auto tmp = nodeQueue.front();
                nodeQueue.pop();
                cur.push_back(tmp->val);
                if (tmp->left != nullptr) { nodeQueue.push(tmp->left); }
                if (tmp->right != nullptr) { nodeQueue.push(tmp->right); }
            }
            if (even) { reverse(begin(cur), end(cur)); }
            even = !even;
            ans.push_back(cur);
        }
        return ans;
    }
};