class Solution {
public:
    int mini = INT_MAX;
    int prev = INT_MAX;
    void check(TreeNode* root){
        if(root == NULL) return;
        
        check(root->left);
        int diff = abs(prev - root->val);
        mini = min(mini,diff);
        prev = root->val;
        check(root->right);

    }
    int minDiffInBST(TreeNode* root) {
        check(root);
        return mini;
    }
};
