Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]


class Solution {
public:
    void combinations(vector<int>& candidates, vector<int> v, vector<vector<int>>& ans, int target, int idx){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0) return;

        for(int i=idx;i<candidates.size();i++){
            if (i > idx && candidates[i] == candidates[i - 1]) continue; // skip duplicates

            if (candidates[i] > target) break; // optimization since array is sorted

            v.push_back(candidates[i]);
            combinations(candidates,v,ans,target - candidates[i],i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;

        combinations(candidates,v,ans,target,0);
        return ans;
        
    }
};
