// T.L.E

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int n = height.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int leftMax = height[i];
            int rightMax = height[i];

            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, height[j]);
            }
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }

            res += min(leftMax, rightMax) - height[i];
        }
        return res;
    }
};

// Accepted 

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};

// Accepted Stack 

class Solution {
public:
    int trap(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0; // Edge case

        vector<int> nge(n, 0); // Right max array
        vector<int> pge(n, 0); // Left max array

        stack<int> st;
        st.push(nums[n - 1]);
        nge[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            nge[i] = max(nge[i + 1], nums[i]);
        }

        stack<int> gt;
        gt.push(nums[0]);
        pge[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pge[i] = max(pge[i - 1], nums[i]);
        }

        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            int minHeight = min(pge[i], nge[i]);
            if (minHeight > nums[i]) {
                count += minHeight - nums[i];
            }
        }

        return count;
        
    }
};

// Two Pointer 

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

