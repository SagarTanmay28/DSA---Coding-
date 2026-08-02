//Approach (Using Line Sweep/Difference Array Technique)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);

        for(auto &b : bookings) {
            int start = b[0];
            int end = b[1];
            int count = b[2];

            diff[start] += count;
            diff[end+1] -= count;
        }

        //Cumulative sum
        vector<int> result;
        int cumSum = 0;
        for(int i = 1; i <= n; i++) {
            cumSum += diff[i];
            result.push_back(cumSum);
        }

        return result;
    }
};


