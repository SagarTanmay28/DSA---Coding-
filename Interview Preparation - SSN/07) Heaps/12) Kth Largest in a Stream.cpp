Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element) after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer will be -1 for that insertion. 

Return a list of size n, where each element represents the Kth largest value after the corresponding insertion.

Examples :

Input: arr[] = [1, 2, 3, 4, 5, 6], k = 4
Output: [-1, -1, -1, 1, 2, 3]
Explanation: 
After 1, the steam is [1]. The 4th largest does not exist. Output is -1.
After 2, the stream is [1, 2]. The 4th largest does not exist. Output is -1.
After 3, the stream is [1, 2, 3]. The 4th largest does not exist. Output is -1.
After 4, the stream is [1, 2, 3, 4]. The 4th largest is 1.
After 5, the stream is [1, 2, 3, 4, 5]. The 4th largest is 2.
After 6, the stream is [1, 2, 3, 4, 5, 6]. The 4th largest is 3.

class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            
            if(pq.size() < k) ans[i] = -1;
            else if(pq.size() > k){
                pq.pop();
                ans[i] = pq.top();
            }
            else ans[i] = pq.top();
        }
        
        return ans;
        
    }
};
