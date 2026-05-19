// Binary Search 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }

        return 0.0;
    }
};

// My Solution 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> v(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                v[k]=nums1[i];
                i++;
            }
            else {
                v[k]=nums2[j];
                j++;
            }
            k++;
        }
        if(i>=m){
            while(j<n){
                v[k]=nums2[j];
                j++;
                k++;
            }
        }
        if(j>=n){
            while(i<m){
                v[k]=nums1[i];
                i++;
                k++;
            }
        }
        double ans;

        if((m+n)%2==0){
           ans = (double)( v[(m+n)/2]+v[((m+n)/2)-1] )/2; // or just divide by 2.0 instead of 2
        }
        else ans = (double)v[(m+n)/2];

        return ans;
        
    }
};
