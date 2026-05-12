// Direct Method 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        if(first == nums.size() || nums[first] != target){
            return {-1, -1};
        }

        return {first, last};
    }
};

// Binary Search 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = -1;
        // First
        int lo = 0;
        int hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                first = mid;
                hi = mid - 1;
            }
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }


        // Second 
        int second = -1;
        lo = 0;
        hi = n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                second = mid;
                lo = mid + 1;
            }
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        
        if(first == -1) return {-1,-1};

        return {first,second};
        
    }
};
