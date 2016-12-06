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
    TreeNode* sortedArrayToBSTImpl(vector<int>& nums, int beginIndex, int endIndex) {
        if (beginIndex > endIndex) { return nullptr; }
        int mid = (beginIndex + endIndex) / 2;
        TreeNode* tmp = new TreeNode(nums[mid]);
        tmp->left = sortedArrayToBSTImpl(nums, beginIndex, mid - 1);
        tmp->right = sortedArrayToBSTImpl(nums, mid + 1, endIndex);
        return tmp;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) { return nullptr; }
        return sortedArrayToBSTImpl(nums, 0, nums.size() - 1);
    }
};