Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Tree:

        3
      /   \
     1     4
    /     / \
   3     1   5

Good nodes are highlighted blue:

Root 3 ✅
Left 3 ✅
4 ✅
5 ✅

Total = 4

class Solution {
public:
    int count = 0;
    void dfs(TreeNode* root, int greaterSoFar){
        if(root == NULL) return;

        if(root->val >= greaterSoFar){
            count++;
            greaterSoFar = root->val;
        }

        dfs(root->left,greaterSoFar);
        dfs(root->right,greaterSoFar);

    }
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return count;
    }
};
