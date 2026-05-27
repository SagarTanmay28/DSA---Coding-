Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.


class Solution { // VIMP Post Order DFS Dry Run Please 
public:
    int maxLen = 0;

    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftCount = 0;
        int rightCount = 0;

        if(root->left && root->left->val == root->val){
            leftCount = left + 1;
        }
        if(root->right && root->right->val == root->val){
            rightCount = right + 1;
        }

        maxLen = max(maxLen, leftCount + rightCount);
        return max(leftCount,rightCount);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxLen;
        
    }
};
