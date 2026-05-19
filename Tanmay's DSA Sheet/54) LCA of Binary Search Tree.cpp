class Solution { // 2nd Solution 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
         else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
         return root;
    }
};




class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;

        return left ? left : right;
        
    }
};
