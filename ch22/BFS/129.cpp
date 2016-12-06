class Solution {
private:
    int sum;
    void sumNumberImpl(TreeNode* root, string str) {
        if (!root->left && !root->right) { sum += atoi((str + int2str(root->val)).c_str()); return; }
        if (root->left) { sumNumberImpl(root->left, str + int2str(root->val)); }
        if (root->right) { sumNumberImpl(root->right, str + int2str(root->val)); }
    }
    string int2str(int num) {
        stringstream ss;
        ss << num;
        return ss.str();
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) { return 0; }
        sumNumberImpl(root, "");
        return sum;
    }
};