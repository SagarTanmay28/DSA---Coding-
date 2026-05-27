You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.


class Solution {
public:
    int maxDepth;
    int result;

    void dfs(TreeNode* root, int currDepth){
        if(root==NULL) return;

        if(currDepth > maxDepth){
            maxDepth = currDepth;
            result = root->val;
        }
        dfs(root->left,currDepth+1);
        dfs(root->right,currDepth+1);
    }


    int findBottomLeftValue(TreeNode* root) {
        maxDepth = -1;
        dfs(root,0);
        return result;
        
    }
};
