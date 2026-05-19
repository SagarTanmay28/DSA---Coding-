class Solution {
public:
    int check(int mid, int days, vector<int>& nums){
        int n = nums.size();

        int count = 0;
        int no_of_days = 1;

        for(int i=0;i<n;i++){
            count += nums[i];
            if(nums[i] > mid) return false;
            else if(count <= mid) continue;
            else{
                no_of_days += 1;
                count = nums[i];
            }
        }


        return no_of_days <= days;
    }

    int shipWithinDays(vector<int>& nums, int days) {
        int n = nums.size();

        int lo = 1;
        int hi = accumulate(nums.begin(),nums.end(),0);

        int min_days = INT_MAX;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(check(mid,days,nums)){
                min_days = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return min_days;
    }
};
    }
};
