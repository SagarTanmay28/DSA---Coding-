You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.


// Brute Force 
class Solution {
public:
    void root_to_leaf(TreeNode* root, vector<int> v, vector<vector<int>> &ans){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            ans.push_back(v);
            return;
        }

        v.push_back(root->val);
        root_to_leaf(root->left,v,ans);
        root_to_leaf(root->right,v,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;

        root_to_leaf(root,v,ans);

        int n = ans.size();
        vector<string> nums;

        for(int i=0;i<n;i++){
            auto arr = ans[i];
            string s = "";

            for(int j=arr.size()-1;j>=0;j--){
                char ch = arr[j] + 'a';
                s += ch;
            }

            nums.push_back(s);
        }

        sort(nums.begin(),nums.end());

        return nums[0];
    }
};

// Optimal 
class Solution {
public:

    string ans = "~";
    // "~" is lexicographically larger than lowercase strings

    void dfs(TreeNode* root, string curr){

        if(root == NULL) return;

        // add current char at FRONT
        curr = char(root->val + 'a') + curr;

        // leaf node
        if(root->left == NULL && root->right == NULL){

            ans = min(ans, curr);
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    string smallestFromLeaf(TreeNode* root) {

        dfs(root, "");

        return ans;
    }
};
