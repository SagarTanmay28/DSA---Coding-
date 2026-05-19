Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.


// Recursion 
class Solution {
public:

    bool solve(int i, vector<int>& arr, vector<int>& vis){

        if(i<0 || i>=arr.size() || vis[i])
            return false;

        if(arr[i] == 0)
            return true;

        vis[i] = 1;

        return solve(i+arr[i], arr, vis) ||
               solve(i-arr[i], arr, vis);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<int> vis(arr.size(),0);

        return solve(start, arr, vis);
    }
};

