class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        if(root->val != subRoot->val) return false;
        
        bool leftAns = check(root->left,subRoot->left);
        if(leftAns == false) return false;

        bool rightAns = check(root->right,subRoot->right);
        if(rightAns == false) return false;

        return true;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(check(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};
