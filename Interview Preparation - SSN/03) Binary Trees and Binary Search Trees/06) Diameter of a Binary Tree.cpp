Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.


class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    
    void helper(TreeNode* root, int &maxDia){
        if(root == NULL) return;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia,dia);
        helper(root->left,maxDia);
        helper(root->right,maxDia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root,maxDia);
        return maxDia;    
    }
};
