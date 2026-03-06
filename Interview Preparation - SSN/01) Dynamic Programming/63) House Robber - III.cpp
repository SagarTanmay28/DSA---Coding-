class Solution {
public:
    int cost(TreeNode* root, unordered_map<TreeNode*,int>& mp){
        if(mp.find(root) != mp.end()) return mp[root];
        int ans = root->val;

        if(root->left){
            ans += cost(root->left->left,mp) + cost(root->left->right,mp);
        }
        if(root->right){
            ans += cost(root->right->left,mp) + cost(root->right->right,mp);
        }

        ans = max(ans,cost(root->left,mp) + cost(root->right,mp));

        mp[root] = ans;

        return ans;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> mp;
        mp[NULL] = 0;

        return cost(root,mp);
        
    }
};
