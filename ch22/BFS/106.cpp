class Solution {
private:
    TreeNode* helper(vector<int>& inorder, int i, int j, vector<int>& postorder, int ii, int jj) {
        if (i >= j || ii >= jj) { return nullptr; }
        int mid = postorder[jj - 1];
        auto rootPos = find(inorder.begin() + i, inorder.begin() + j, mid);
        int diff = rootPos - inorder.begin() - i;
        TreeNode* root = new TreeNode(mid);
        root->left = helper(inorder, i, i + diff, postorder, ii, ii + diff);
        root->right = helper(inorder, i + diff + 1, j, postorder, ii + diff, jj - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
