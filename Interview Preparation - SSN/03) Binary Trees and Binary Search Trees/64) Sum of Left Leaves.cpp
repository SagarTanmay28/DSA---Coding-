Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.


class Solution {
public:
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int sum = 0;

        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL){
            sum += root->left->val;
        }

        sum += helper(root->left);
        sum += helper(root->right);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root);
        
    }
};
