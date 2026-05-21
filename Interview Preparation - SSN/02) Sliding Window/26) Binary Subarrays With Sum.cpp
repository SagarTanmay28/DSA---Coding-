Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

// Sliding Window 

class Solution {
public:

    int atMost(vector<int>& nums, int goal){
        int n = nums.size();
        if(goal < 0) return 0;
        
        int sum = 0;
        int count = 0;
        int i = 0;
        int j = 0;
        // Sliding Window
        while(j < n){
            sum += nums[j];

            while(sum > goal){
                sum -= nums[i];
                i++;
            }

            // all subarrays ending at j
            count += (j - i + 1);
            j++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};



// Cumulative Sum + Map 

class Solution { // Cumulative Sum + Map
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            int rem = currSum - goal;
            if(mp.find(rem) != mp.end()) ans += mp[rem];
            mp[currSum]++;
        }
        return ans;
        
    }
};
