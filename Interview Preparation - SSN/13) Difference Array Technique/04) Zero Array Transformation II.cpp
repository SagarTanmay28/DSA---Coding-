You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]

Output: 2

Explanation:

For i = 0 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [1, 0, 1].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.
Example 2:

Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]

Output: -1

Explanation:

For i = 0 (l = 1, r = 3, val = 2):
Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
The array will become [4, 1, 0, 0].
For i = 1 (l = 0, r = 2, val = 1):
Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
The array will become [3, 0, 0, 0], which is not a Zero Array.

//Approach-1 - Difference Array Technique with Linear Query Check
//T.C : O(Q * (Q + n))
//S.C : O(n)
class Solution {
public:
    int n;
    int Q;

    bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);

        //O(Q)
        for(int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r   = queries[i][1];
            int x     = queries[i][2];

            diff[l] += x;
            if(r+1 < n)
                diff[r+1] -= x;
        }

        int cumSum = 0;
        //O(n)
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];

            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                return false;
            }
        }

        return true;

    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        auto lambda = [](int x) {
            return x == 0;
        };

        if(all_of(begin(nums), end(nums), lambda)) {
            return 0; //no query required because all are already zero
        }

        for(int i = 0; i < Q; i++) { //O(Q * (Q + n))
            if(checkWithDifferenceArrayTeq(nums, queries, i) == true) {
                return i+1;
            }
        }

        return -1;
    }
};


//Approach-2 - Difference Array Technique with Binary Search for Query Check
//T.C : O(log(Q) * (Q + n))
//S.C : O(n)
class Solution {
public:
    int n;
    int Q;

    bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);

        //O(Q)
        for(int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r   = queries[i][1];
            int x     = queries[i][2];

            diff[l] += x;
            if(r+1 < n)
                diff[r+1] -= x;
        }

        int cumSum = 0;
        //O(n)
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];

            diff[i] = cumSum;

            if(nums[i] - diff[i] > 0) { //nums[i] 0 nahi ban paya
                return false;
            }
        }

        return true;

    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        auto lambda = [](int x) {
            return x == 0;
        };

        if(all_of(begin(nums), end(nums), lambda)) {
            return 0; //no query required because all are already zero
        }

        int l = 0;
        int r = Q-1;
        int k = -1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(checkWithDifferenceArrayTeq(nums, queries, mid) == true) {
                k = mid+1; //possible answer
                r = mid-1;
            } else {
                 l = mid+1;
            }
        }

        return k;
    }
};
