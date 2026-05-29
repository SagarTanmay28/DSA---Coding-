Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]



// Heaps 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        priority_queue< pair<int,int> > pq;
        for(int i=0;i<n;i++){
            pq.push({abs(x-arr[i]),arr[i]});
            if(pq.size() > k) pq.pop();
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

// Binary Search 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare distances from x
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1; // Move right
            } else {
                right = mid; // Move left
            }
        }

        // From index `left`, take k elements
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
        
    }
};
