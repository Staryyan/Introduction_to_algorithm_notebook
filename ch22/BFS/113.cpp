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
    vector<vector<int>> answer;
    int sum;
    void pathSumImpl(TreeNode* root, vector<int> path, int _sum) {
        path.push_back(root->val);
        _sum += root->val;
        if (!root->left && !root->right) {
            if (_sum == sum) { answer.push_back(path); }
        }
        if (root->left) { pathSumImpl(root->left, path, _sum); }
        if (root->right) { pathSumImpl(root->right, path, _sum); }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) { return answer; }
        this->sum = sum;
        pathSumImpl(root, vector<int>{}, 0);
        return answer;
    }
};