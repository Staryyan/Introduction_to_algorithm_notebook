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
    TreeNode* helper(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj) {
        if (i >= j || ii >= jj) { return nullptr; }
        int mid = preorder[i];
        auto rootPos = find(inorder.begin() + ii, inorder.begin() + jj, mid);
        int diff = rootPos - inorder.begin() - ii;
        TreeNode* root = new TreeNode(mid);
        root->left = helper(preorder, i + 1, i + 1 + diff, inorder, ii, ii + diff);
        root->right = helper(preorder, i + 1 + diff, j, inorder, ii + diff + 1, jj);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};