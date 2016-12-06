#include "init.h"
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
    int maxSum = INT_MIN;
    int helper(TreeNode* root) {
        if (!root) { return 0; }
        int leftSum = helper(root->left);
        leftSum = leftSum < 0 ? 0 : leftSum;
        int rightSum = helper(root->right);
        rightSum = rightSum < 0 ? 0 : rightSum;
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        return max(root->val + leftSum, root->val + rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        return max(maxSum, helper(root));
    }
};
