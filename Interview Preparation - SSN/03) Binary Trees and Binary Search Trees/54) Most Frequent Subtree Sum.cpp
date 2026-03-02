class Solution {
public:
    int fill(TreeNode* root, int& maxFreq, unordered_map<int,int>& mp){
        if(root == NULL) return 0;

        // sum of left & right subtree
        int left = fill(root->left,maxFreq,mp);
        int right = fill(root->right,maxFreq,mp);

        // totalSum

        int totalSum = root->val + left + right;

        // store
        mp[totalSum]++;
        maxFreq = max(maxFreq,mp[totalSum]);


        return totalSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == NULL) return {};

        unordered_map<int,int> mp;
        int maxFreq = 0;
        
        fill(root,maxFreq,mp);

        if(root->left != NULL) findFrequentTreeSum(root->left);
        if(root->right != NULL) findFrequentTreeSum(root->right);

        vector<int> ans;
        for(auto &x : mp){
           if(x.second == maxFreq) ans.push_back(x.first);
        }

        
        return ans;
        
    }
};
