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
    int times{0};
    int DFS(TreeNode* root, int currSum, int sum) {
        if (!root) { return 0;}
        int curr = currSum + root->val;
        return (curr == sum) + DFS(root->left, curr, sum) + DFS(root->right, curr, sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) { return 0; }
        return DFS(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};