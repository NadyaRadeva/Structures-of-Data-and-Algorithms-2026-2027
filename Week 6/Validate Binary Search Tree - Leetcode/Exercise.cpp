class Solution {
public:
    bool isValid(TreeNode* root, long long minValue, long long maxValue) {
        if (!root) {
            return true;
        }

        if (root->val <= minValue || root->val >= maxValue) {
            return false;
        }

        return isValid(root->left, minValue, root->val) &&
               isValid(root->right, root->val, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
