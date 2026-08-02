You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.

 

Example 1:

Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.
Example 2:

Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
Example 3:

Input: intervals = [[1,4],[2,3],[3,4]]
Output: [-1,2,-1]
Explanation: There is no right interval for [1,4] and [3,4].
The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.

// My Approach :: 

  class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        map<pair<int,int>, int> mp;

        for (int i = 0; i < n; i++)
            mp[{intervals[i][0], intervals[i][1]}] = i;

        sort(intervals.begin(), intervals.end());

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {

            int ce = intervals[i][1];

            // Find first interval whose start >= current end
            auto it = lower_bound(
                intervals.begin(),
                intervals.end(),
                vector<int>{ce, INT_MIN}
            );

            if (it != intervals.end()) {
                ans[mp[{intervals[i][0], intervals[i][1]}]] =
                    mp[{(*it)[0], (*it)[1]}];
            }
        }

        return ans;
    }
};

// Best Code 

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<pair<int,int>> starts;

        for(int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {

            int end = intervals[i][1];

            auto it = lower_bound(
                starts.begin(),
                starts.end(),
                make_pair(end, -1)
            );

            if(it != starts.end())
                ans[i] = it->second;
        }

        return ans;
    }
};
