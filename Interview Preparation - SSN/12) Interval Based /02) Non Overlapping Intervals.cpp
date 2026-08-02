Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int n = intervals.size(); 
        
        int count = 0;
        int i = 0, j = 1;
        
        while(j < n) {
            vector<int> curr_interval = intervals[i];
            vector<int> next_interval = intervals[j];
            
            int curr_start = curr_interval[0];
            int curr_end   = curr_interval[1];
            
            int next_start = next_interval[0];
            int next_end   = next_interval[1];
            
            if(curr_end <= next_start) { //SAFE
                i = j;
                j++;
            } else if(curr_end <= next_end) {
                /*
                    GREEDY : Remove next interval as it has high chances to
                             overlap with future intervals
                */
                j++;
                count++;
            } else if(curr_end > next_end) {
                /*
                    GREEDY : Remove current interval as it has high chances to
                             overlap with future intervals
                */
                i = j;
                j++;
                count++;
            }
        }

        return count;

    }
};
