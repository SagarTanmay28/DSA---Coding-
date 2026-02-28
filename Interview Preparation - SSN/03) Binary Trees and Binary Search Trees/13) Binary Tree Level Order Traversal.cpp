class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }

    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v){
        if(root == NULL) return;

        if(curr == level){
            v.push_back(root->val);
            return;
        }

        nthLevel(root->left,curr+1,level,v);
        nthLevel(root->right,curr+1,level,v);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> v;
            nthLevel(root,0,i,v);
            ans.push_back(v);
        }

        return ans;
    }
};
