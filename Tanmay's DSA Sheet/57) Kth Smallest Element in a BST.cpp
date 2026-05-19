class Solution {
public:
    int count = 0;
    int result = -1;

    void inorder(TreeNode* root, int k) {
        if (!root || count >= k) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            result = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
