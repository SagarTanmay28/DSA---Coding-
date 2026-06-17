Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10


// Brute Force 

class Solution {
public:
    void helper(vector<int>& nums, vector<int> v, set<vector<int>>& st, int idx){
        if(idx == nums.size()){
            st.insert(v);
            return;
        }
        helper(nums,v,st,idx+1);
        v.push_back(nums[idx]);
        helper(nums,v,st,idx+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        set< vector<int> > st;

        sort(nums.begin(),nums.end());

        helper(nums,v,st,0);

        for(auto vec : st){
            ans.push_back(vec);
        }

        return ans;
        
    }
};


// Optimal 

class Solution {
public:
    
    void helper(vector<int>& nums, vector<int>& curr,
                vector<vector<int>>& ans, int idx) {
        
        ans.push_back(curr);

        for(int i = idx; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if(i > idx && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            helper(nums, curr, ans, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        helper(nums, curr, ans, 0);

        return ans;
    }
};
