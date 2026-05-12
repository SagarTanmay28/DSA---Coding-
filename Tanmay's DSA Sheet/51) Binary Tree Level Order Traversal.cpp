class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }

    void nthLevel(int curr, int level, TreeNode* root, vector<int> &v){
        if(root == NULL) return;

        if(curr == level){
            v.push_back(root->val);
            return;
        }

        nthLevel(curr+1,level,root->left,v);
        nthLevel(curr+1,level,root->right,v);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans;

        for(int i=1;i<=n;i++){
            vector<int> v;
            nthLevel(1,i,root,v);
            ans.push_back(v);
        }

        return ans;
    }
};
