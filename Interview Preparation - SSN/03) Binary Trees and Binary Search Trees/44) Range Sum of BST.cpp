class Solution {
public:
    void inorder(TreeNode* root, int lo, int hi, int &sum){
        if(root == NULL) return;
        inorder(root->left,lo,hi,sum);
        if(root->val >= lo && root->val <= hi) sum += root->val;
        inorder(root->right,lo,hi,sum);
    }

    int rangeSumBST(TreeNode* root, int lo, int hi) {
        
        int sum = 0;
        inorder(root,lo,hi,sum);
        return sum;
        
    }
};
