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
private:
    void inorderTraversal(TreeNode* root, vector<int>& ans) {
        if (!root) { return; }
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorderTraversal(root, ans);
        return ans[k - 1];
    }
};