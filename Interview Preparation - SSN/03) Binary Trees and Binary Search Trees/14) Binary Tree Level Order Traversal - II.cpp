Given the root of a binary tree, return the bottom-up level order traversal
of its nodes' values. (i.e., from left to right, level by level from leaf to root).

// with reverse
class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<vector<int>> &ans ){
        if(root == NULL) return;
        if(curr == level){
            ans[level].push_back(root->val);
            return;
        }
        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            nthLevel(root,0,i,ans);
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};

// without reverse

class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, int total,
                  vector<vector<int>> &ans){
        if(root == NULL) return;

        if(curr == level){
            ans[total - level - 1].push_back(root->val);
            return;
        }

        nthLevel(root->left, curr + 1, level, total, ans);
        nthLevel(root->right, curr + 1, level, total, ans);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = levels(root);

        vector<vector<int>> ans(n);

        for(int i = 0; i < n; i++){
            nthLevel(root, 0, i, n, ans);
        }

        return ans;
    }
};
