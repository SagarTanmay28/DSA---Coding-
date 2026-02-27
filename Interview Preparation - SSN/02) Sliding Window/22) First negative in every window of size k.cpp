Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.

// TLE - 1110/1111
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        
        vector<int> ans(n-k+1,0);
        
        int p = -1;
        for(int i=0;i<k;i++){
            if(arr[i] < 0){
                p = i;
                break;
            }
        }
        
        if(p == -1) ans[0] = 0;
        else ans[0] = arr[p];
        
        int i = 1;
        int j = k;
        
        while(j < n){
            if(p >= i) ans[i] = arr[p];
            else{
                bool flag = false;
                for(int x=i;x<=j;x++){
                    if(arr[x] < 0){
                        flag = true;
                        p = x;
                        break;
                    }
                }
                if(flag == true) ans[i] = arr[p];
                else ans[i] = 0;
            }
            
            i++;
            j++;
        }
        return ans;
        
    }
};

// Sliding Window + Queue
class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> ans;
        
        deque<int> dq; // stores indices of negative numbers
        
        int i = 0;
        
        for(int j = 0; j < n; j++) {
            
            if(arr[j] < 0)
                dq.push_back(j);
            
            // window size reached
            if(j - i + 1 == k) {
                
                if(dq.empty())
                    ans.push_back(0);
                else
                    ans.push_back(arr[dq.front()]);
                
                // remove element going out
                if(!dq.empty() && dq.front() == i)
                    dq.pop_front();
                
                i++;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        int fstNegIdx = 0;
        vector<int> res;
        int n = arr.size();  // Use size() for vectors
    
        for (int i = k - 1; i < n; i++) {
            
            // Skip out of window and positive elements
            while ((fstNegIdx < i) && (fstNegIdx <= i - k || arr[fstNegIdx] >= 0)) {
                fstNegIdx++;
            }
    
            // Check if a negative element is found, 
            // otherwise use 0
            if (fstNegIdx < n && arr[fstNegIdx] < 0) {
                res.push_back(arr[fstNegIdx]);
            }
            else {
                res.push_back(0);
            }
        }
        return res;
    }
};
