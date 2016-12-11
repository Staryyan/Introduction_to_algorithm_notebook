#include <iostream>
#include <vector>
using namespace std;
#define MaxT 10
struct TreeNode {
    vector<int> keys;
    vector<TreeNode*> childs;
    int n;
    bool leaf;
    TreeNode(int t) {
        keys = vector<int>(2 * t, 0);
        childs = vector<TreeNode*>(2 * t, nullptr);
        n = 0;
        leaf = true;
    }
};
class BTree {
private:
    TreeNode* root;
    int t;
    pair<TreeNode*, int> bTreeSearchImpl(TreeNode* root, int val) {
        int i = 0;
        while (i < root->n && val > root->keys[i]) { i++; }
        if (i < root->n && val == root->keys[i]) { return {root, i}; }
        else if (root->leaf) {
            return {nullptr, 0};
        } else {
            return bTreeSearchImpl(root->childs[i], val);
        }
    };
    void bTreeSplitChild(TreeNode* root, int i) {
        TreeNode* z = new TreeNode(this->t);
        TreeNode* y = root->childs[i];
        z->leaf = y->leaf;
        z->n = this->t - 1;
        for (int j = 0; j < this->t - 1; ++j) {
            z->keys[j] = y->keys[j + this->t];
        }
        if (!y->leaf) {
            for (int j = 0; j < this->t - 1; ++j) {
                z->childs[j] = y->childs[j + this->t];
            }
        }
        y->n = this->t - 1;
        for (int k = root->n - 1; k >= i + 1; --k) {
            root->childs[k + 1] = root->childs[k];
        }
        root->childs[i + 1] = z;
        for (int l = root->n - 1; l >= i; --l) {
            root->keys[l + 1] = root->keys[l];
        }
        root->keys[i] = y->keys[this->t - 1];
        root->n++;
    }
    void bTreeInsertNotFull(TreeNode* root, int k) {
        int i = root->n;
        if (root->leaf) {
            while (i > 0 && k < root->keys[i - 1]) {
                root->keys[i + 1] = root->keys[i];
                i--;
            }
            root->keys[i] = k;
            root->n++;
        } else {
            i--;
            while (i >= 0 && k < root->keys[i]) {
                i--;
            }
            i++;
            if (root->childs[i]->n == 2 * t - 1) {
                bTreeSplitChild(root, i);
                if (k > root->keys[i]) {
                    i++;
                }
            }
            bTreeInsertNotFull(root->childs[i], k);
        }
    }
    void traversalImpl(TreeNode* root) {
        if (root != nullptr) {
            for (int i = 0; i < root->n; ++i) {
                cout << root->keys[i] << " ";
            }
            cout << endl;
            for (int j = 0; j < root->childs.size(); ++j) {
                traversalImpl(root->childs[j]);
            }
        }
    }
public:
    BTree(int t) {
        this->t = t;
        root = new TreeNode(this->t);
    }
    pair<TreeNode*, int> bTreeSearch(int val) {
        return bTreeSearchImpl(root, val);
    };
    void bTreeInsert(int k) {
        if (root->n == 2 * this->t - 1) {
            TreeNode* s = new TreeNode(this->t);
            TreeNode* r = this->root;
            this->root = s;
            s->leaf = false;
            s->childs[0] = r;
            bTreeSplitChild(s, 0);
            bTreeInsertNotFull(s, k);
        } else {
            bTreeInsertNotFull(this->root, k);
        }
    }
    void traversal() {
        traversalImpl(this->root);
    }
};
int main() {
    BTree tree(3);
    for (int i = 0; i < 18; ++i) {
        tree.bTreeInsert(i);
    }
    tree.bTreeInsert(20);
    tree.traversal();
}
