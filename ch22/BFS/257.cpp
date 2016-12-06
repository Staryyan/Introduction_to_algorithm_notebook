class Solution {
    vector<string> answer;
    void binaryTreePathsImpl(TreeNode* root, string tmp) {
        if (!root->left && !root->right) { answer.push_back(tmp + "->" + int2str(root->val)); }
        if (root->left) { binaryTreePathsImpl(root->left, tmp + "->" + int2str(root->val)); }
        if (root->right) { binaryTreePathsImpl(root->right, tmp + "->" + int2str(root->val)); }
    }
    string int2str(int num) {
        stringstream ss;
        ss << num;
        return ss.str();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) { return answer; }
        if (!root->left && !root->right) { answer.push_back(int2str(root->val)); }
        if (root->left) { binaryTreePathsImpl(root->left, int2str(root->val)); }
        if (root->right) { binaryTreePathsImpl(root->right, int2str(root->val)); }
        return answer;
    }
};
