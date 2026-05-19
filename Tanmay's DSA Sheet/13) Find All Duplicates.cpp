Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> v;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                v.push_back(nums[i]);
                while(i+1 < n && nums[i]==nums[i-1]){
                    i++;
                }
            }
        }
        return v;
        
    }
};
