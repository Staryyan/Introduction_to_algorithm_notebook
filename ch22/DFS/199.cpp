#include <iostream>
#include <vector>
#include <queue>
using namespace std;
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) { return ans; }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            ans.push_back(nodeQueue.front()->val);
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = nodeQueue.front();
                if (tmp->right != nullptr) { nodeQueue.push(tmp->right); }
                if (tmp->left != nullptr) { nodeQueue.push(tmp->left); }
                nodeQueue.pop();
            }
        }
        return ans;
    }
};
