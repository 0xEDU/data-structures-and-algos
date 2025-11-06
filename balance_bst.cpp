#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* createBalancedBST(const vector<int> &inorder, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) /2;

        TreeNode *leftSubtree = createBalancedBST(inorder, start, mid - 1);
        TreeNode *rightSubtree = createBalancedBST(inorder, mid + 1, end);

        return new TreeNode(inorder[mid], leftSubtree, rightSubtree);
    }

    void inorderTraversal(TreeNode *root, vector<int> &inorder) {
        if (root == nullptr) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);

        int size = inorder.size();

        return createBalancedBST(inorder, 0, size - 1);
    }
};

int main() {
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);
	root->right->right->right = new TreeNode(4);

	Solution s;
	s.balanceBST(root);

	return 0;
}
