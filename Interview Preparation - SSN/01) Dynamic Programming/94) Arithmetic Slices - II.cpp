// Brute Force 
class Solution {
public:

    bool isArithmetic(vector<int>& seq) {

        if (seq.size() < 3)
            return false;

        int diff = seq[1] - seq[0];

        for (int i = 2; i < seq.size(); i++) {

            if (seq[i] - seq[i - 1] != diff)
                return false;
        }

        return true;
    }

    void generate(vector<int>& nums,
                  int i,
                  vector<int>& current,
                  int& ans) {

        // We have considered every element
        if (i == nums.size()) {

            if (isArithmetic(current))
                ans++;

            return;
        }

        // -----------------------
        // Choice 1: Take nums[i]
        // -----------------------
        current.push_back(nums[i]);

        generate(nums, i + 1, current, ans);

        current.pop_back();

        // --------------------------
        // Choice 2: Don't take nums[i]
        // --------------------------
        generate(nums, i + 1, current, ans);
    }

    int numberOfArithmeticSlices(vector<int>& nums) {

        int ans = 0;

        vector<int> current;

        generate(nums, 0, current, ans);

        return ans;
    }
};

// Optimal 

//T.C : O(n^2)
//S.C : O(n^2) - because of the 2D array mp, where each row mp[i] represents a different index in the input vector nums
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<long, int> mp[n];
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                auto diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);
                
                int count_at_j = it==end(mp[j]) ? 0 : it->second;
                
                mp[i][diff] += count_at_j+1;
                result      += count_at_j;
                
            }
        }
        return result;
    }
};
