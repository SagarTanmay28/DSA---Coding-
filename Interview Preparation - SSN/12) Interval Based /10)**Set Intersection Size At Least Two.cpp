You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.

For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
Return the minimum possible size of a containing set.

 

Example 1:

Input: intervals = [[1,3],[3,7],[8,9]]
Output: 5
Explanation: let nums = [2, 3, 4, 8, 9].
It can be shown that there cannot be any containing array of size 4.
Example 2:

Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
Output: 3
Explanation: let nums = [2, 3, 4].
It can be shown that there cannot be any containing array of size 2.
Example 3:

Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
Output: 5
Explanation: let nums = [1, 2, 3, 4, 5].
It can be shown that there cannot be any containing array of size 4.


class Solution {
public:
    
    // why decending ?? 
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int result = 0;
        int first = -1;
        int second = -1;

        sort(intervals.begin(), intervals.end(),
     [](const vector<int>& a, const vector<int>& b){
         if (a[1] == b[1]) return a[0] > b[0];
         return a[1] < b[1];
     });

        for(int i=0;i<n;i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            
            if(first >= l) continue;

            if(second >= l){
                result += 1;
                first = second;
                second = r;
            }

            else{
                result += 2;
                first = r - 1;
                second = r;
            }
        }

        return result;
    }
};
 
