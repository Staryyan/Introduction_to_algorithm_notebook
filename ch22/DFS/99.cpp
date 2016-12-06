class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
    void helper(TreeNode* root) {
        if (!root) { return; }
        helper(root->left);
        if (first == nullptr && prev->val >= root->val) { first = prev; }
        if (first != nullptr && prev->val >= root->val) { second = root; }
        prev = root;
        helper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }
};