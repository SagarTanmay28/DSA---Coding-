In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.



Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.

class Solution {
public:
    bool check(int mid, int m, vector<int>& nums){
        int n = nums.size();
        int count = 1;
        int last = nums[0];

        for(int i=1;i<n;i++){
            if(nums[i] - last >= mid){
                count++;
                last = nums[i];
            }
        }

        return count >= m;
    }

    int maxDistance(vector<int>& nums, int m) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int lo = 0;
        int hi = nums[n-1] - nums[0];

        int ans = INT_MIN;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(mid,m,nums)){
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return ans;
    }
};
