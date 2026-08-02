Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1


class Solution {
public:
    static bool myFunction(vector<int>& v1, vector<int>& v2) {
        if(v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0]<v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        if(n == 0 || n == 1)
            return n;
        sort(intervals.begin(), intervals.end(), myFunction);
        result.push_back(intervals[0]);
        
        for(int i = 1; i<n; i++) {
            if(result.back()[0] <= intervals[i][0] && result.back()[1] >= intervals[i][1])
                continue;
            
            result.push_back(intervals[i]);
        }
        
        return result.size();
    }
};
