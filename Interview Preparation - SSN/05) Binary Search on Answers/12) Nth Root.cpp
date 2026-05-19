You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

Examples :

Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16


class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        long long lo = 0;
        long long hi = m;
    
        // Binary Search 
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            long long ans = 1;
            for(int i=1;i<=n;i++){
                ans *= mid;
                
                if(ans > m) break;
            }
            
            if(ans == m) return mid;
            
            if(ans < m) lo = mid + 1;
            else hi = mid - 1;
            
        }
        
        return -1;
        
    }
};
