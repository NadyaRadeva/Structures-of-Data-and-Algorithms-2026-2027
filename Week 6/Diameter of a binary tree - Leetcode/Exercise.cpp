/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int currentDiameter = leftHeight + rightHeight;

        if(currentDiameter > maxDiameter) {
            maxDiameter = currentDiameter;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return maxDiameter;
    }
};
