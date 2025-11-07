struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count = 0;

    pair<int, int> traverse(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        pair<int, int> left = traverse(root->left);
        pair<int, int> right = traverse(root->right);

        int nodeSum = left.first + right.first + root->val;
        int nodeCount = left.second + right.second + 1;

        if (root->val == nodeSum / (nodeCount)) {
            count++;
        }

        return {nodeSum, nodeCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return count;
    }
};
