Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available. Each painter takes 1 unit of time to paint 1 unit length of a board.

Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is - 
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35
Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: A valid optimal partition is - 
Painter 1 → [10, 20, 30] → time = 60
Painter 2 → [40] → time = 40
Job will be complete at time = max(60, 40) = 60
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint all boards sequentially. The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.




class Solution {
  public:
    int check(int mid, int k, vector<int>& arr){
        int n = arr.size();
        
        int painters = 1;
        int count = 0;
        
        for(int i=0;i<n;i++){
            count += arr[i];
            if(mid >= count) continue;
            else{
                painters++;
                count = arr[i];
            }
        }
        
        return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int lo = *max_element(arr.begin(),arr.end());
        int hi = accumulate(arr.begin(),arr.end(),0);
        
        int ans = INT_MAX;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if(check(mid,k,arr)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        return ans;
    }
};
