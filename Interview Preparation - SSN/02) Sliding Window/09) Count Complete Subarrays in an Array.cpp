You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st(nums.begin(),nums.end());

        unordered_map<int,int> mp;
        int count = 0;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            mp[nums[j]]++;

            while(mp.size() == st.size()){
                count += (n - j);

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return count;
    }
};
