class Solution {
public:
    bool check(TreeNode* root, int sum){
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) return sum == root->val;
        return (check(root->left, sum - root->val) || check(root->right, sum - root->val));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root,targetSum);   
    }
};
