class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, vector<vector<int>> &ans){
        if(root == NULL) return;
        if(curr == level){
            ans[level].push_back(root->val);
            return;
        }
        nthLevel(root->left, curr + 1, level, ans);
        nthLevel(root->right, curr + 1, level, ans);
    }

    void average(vector<vector<int>> &ans, vector<double> &result){
        for(int i=0;i<ans.size();i++){
            double sum = 0;
            for(int j=0;j<ans[i].size();j++){
                double num = ans[i][j];
                sum += num;
            }
            result[i] = sum / (ans[i].size());
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            nthLevel(root,0,i,ans);
        }
        vector<double> result(n);
        average(ans,result);
        return result;
        
    }
};
