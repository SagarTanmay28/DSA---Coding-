You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.

class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue< pi, vector<pi>, greater<pi> >pq;

        // filling nums,idx in pq
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size() > k) pq.pop();
        }

        vector<pi> arr;
        while(pq.size()){
            arr.push_back(pq.top());
            pq.pop();
        }

        sort(arr.begin(),arr.end(), [](pi &a, pi &b){
            return a.second < b.second;
        });
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].first);
        }

        return ans;

    }
};
