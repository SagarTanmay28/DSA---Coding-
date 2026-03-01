class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    int maxDepth(TreeNode* root) {
        return levels(root);
    }
};
