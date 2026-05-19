class Solution {
public:
    void helper(TreeNode* root, vector<int> v, int sum, vector<vector<int>> &ans){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum){
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        helper(root->left, v, sum - root->val, ans);
        helper(root->right, v, sum - root->val, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,v,targetSum,ans);
        return ans;  
    }
};
