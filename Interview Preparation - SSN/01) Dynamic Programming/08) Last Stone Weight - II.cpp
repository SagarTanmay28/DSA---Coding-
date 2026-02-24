class Solution {
public:
    int total;
    vector<vector<int>> dp;

    int solve(int i, int currSum, vector<int>& stones) {
        if (i == stones.size()) {
            return abs(total - 2 * currSum);
        }

        if (dp[i][currSum] != -1) {
            return dp[i][currSum];
        }

        // Choice 1: take stone i into group A
        int take = solve(i + 1, currSum + stones[i], stones);

        // Choice 2: don't take stone i into group A
        int skip = solve(i + 1, currSum, stones);

        return dp[i][currSum] = min(take, skip);
    }

    int lastStoneWeightII(vector<int>& stones) {
        total = 0;
        for (int x : stones) total += x;

        int n = stones.size();
        dp.assign(n, vector<int>(total + 1, -1));

        return solve(0, 0, stones);
    }
};
