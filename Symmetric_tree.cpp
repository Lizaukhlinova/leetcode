/*
101. Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return equalTree(root->left, root->right);
    }

    bool equalTree(TreeNode * A, TreeNode * B) {
        if (A == NULL && B == NULL)
            return true;
        if (A == NULL || B == NULL || A->val != B->val)
            return false;
        return equalTree(A->left, B->right) && equalTree(A->right, B->left);
    }
};

int main() {
	Solution s;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

	cout << s.isSymmetric(root) << endl;
	return 0;
}