You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k 
which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between 
any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows in this case is 4, which is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: There are 6 stalls and only 5 cows, we try to place the cows such that the minimum distance between any two cows is as large as possible.
The minimum distance between cows in this case is 1, which is the largest among all possible ways.

  
class Solution {
  public:
    int check(int mid, int k, vector<int>& nums){
        int n = nums.size();
        
        int count = 1;
        int last = nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i] - last >= mid){
                count++;
                last = nums[i];
            }
        }
        
        return count >= k;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        // code here
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        
        int ans = INT_MIN;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if(check(mid,k,nums)){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        
        return ans;
        
    }
};
