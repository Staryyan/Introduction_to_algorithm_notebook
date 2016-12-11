class Solution {
private:
    struct TreeNode {
        int val, copy, leftCnt;
        TreeNode* left, * right;
        TreeNode(int val) {
            this->val = val;
            copy = 1;
            leftCnt = 0;
            left = nullptr;
            right = nullptr;
        }
    };
    int insert(TreeNode* root, int val) {
        if (root->val == val) {
            root->copy++;
            return root->leftCnt;
        } else if (root->val > val) {
            root->leftCnt++;
            if (!root->left) {
                root->left = new TreeNode(val);
                return  0;
            } else {
                return insert(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new TreeNode(val);
                return root->leftCnt + root->copy;
            } else {
                return root->leftCnt + root->copy + insert(root->right, val);
            }
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) { return vector<int>{}; }
        int size = nums.size() - 1;
        if (size <= 0) { return vector<int>{0}; }
        TreeNode* root = new TreeNode(nums[size]);
        vector<int> answer(nums.size(), 0);
        for (int i = size - 1; i >= 0; --i) {
            answer[i] = insert(root, nums[i]);
        }
        return answer;
    }
};