class Solution {
public:
    int size(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    int countNodes(TreeNode* root) {
        return size(root);  
    }
};
