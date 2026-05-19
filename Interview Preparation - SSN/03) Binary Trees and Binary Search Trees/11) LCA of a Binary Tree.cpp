Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

// Approach - 1
class Solution {
public:
    bool exists(TreeNode* root, TreeNode* target){
        if(root == NULL) return false;
        if(root == target) return true;
        return exists(root->left,target) || exists(root->right,target);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
       else if(exists(root->right,p) && exists(root->right,q)) return lowestCommonAncestor(root->right,p,q);
       return root; 
    }
};

// Approach - 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root; // one in left & one in right

        return left ? left : right;
        
    }
};
