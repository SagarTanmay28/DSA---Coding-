
// Simpler but Slower 
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int left = height(root->left);
        int right = height(root->right);

        if(abs(left-right) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// Good Fast Solution 
class Solution {
public:
    int check(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = check(root->left);
        if(leftHeight==-1) return -1;

        int rightHeight = check(root->right);
        if(rightHeight==-1) return -1;

        if(abs(leftHeight-rightHeight) > 1) return -1;

        return max(leftHeight,rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};
