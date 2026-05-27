Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

// Memory Limit Exceeded 
  
  class Solution {
public:
    void root_to_leaf(TreeNode* root, vector<int> v, vector<vector<int>>& nums){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            nums.push_back(v);
            return;
        }

        v.push_back(root->val);
        root_to_leaf(root->left,v,nums);
        root_to_leaf(root->right,v,nums);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<vector<int>> nums;
        vector<int> v;
        root_to_leaf(root,v,nums);

        int count = 0;

        int n = nums.size();
        for(int i=0;i<n;i++){
            vector<int> arr = nums[i];

            unordered_map<int,int> mp;

            int odds = 0;
            int even = 0;

            for(int x : arr) mp[x]++;
            for(auto &x : mp){
                if(x.second % 2 != 0) odds++;
                else even++;
            }

            if(odds > 1) count += 0;
            else count += 1;
        }

        return count;
    }
};

// Memory Limit Exceeded 

class Solution {
public:
    int count = 0;
    void root_to_leaf(TreeNode* root, unordered_map<int,int> mp){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            mp[root->val]++;

            int odds = 0;
            int even = 0;

            
            for(auto &x : mp){
                if(x.second % 2 != 0) odds++;
                else even++;
            }

            if(odds > 1) count += 0;
            else count += 1;
        }

        mp[root->val]++;
        root_to_leaf(root->left,mp);
        root_to_leaf(root->right,mp);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        root_to_leaf(root,mp);

        return count;
    }
};


// Accepted but not Optimal 
class Solution {
public:
    int count = 0;
    void root_to_leaf(TreeNode* root, unordered_map<int,int>& mp){
        if(root == NULL) return;

        mp[root->val]++;

        if(root->left == NULL && root->right == NULL){
            int odds = 0;

            for(auto &x : mp){
                if(x.second % 2 != 0) odds++;
            }

            if(odds <= 1) count++;
        }

        root_to_leaf(root->left, mp);
        root_to_leaf(root->right, mp);

        // backtrack
        mp[root->val]--;
        if(mp[root->val] == 0) mp.erase(root->val);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        root_to_leaf(root,mp);

        return count;
    }
};
