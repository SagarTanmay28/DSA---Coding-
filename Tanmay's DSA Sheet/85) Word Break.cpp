Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

class Solution {
public:
    int n;
    unordered_set<string> st;
   

    int solve(int idx, string& s, vector<int>& dp){
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        string currString = "";
        int min_extra = n;

        for(int i=idx;i<n;i++){
            currString += s[i];

            int curr_extra = (st.find(currString) == st.end()) ? currString.size() : 0;
            int next_extra = solve(i+1,s,dp);

            int total_extra = curr_extra + next_extra;
            min_extra = min(min_extra,total_extra);
        }

        return dp[idx] = min_extra;
    }

    int wordBreak(string s, vector<string>& dictionary) {
        n = s.size();
        for(string& x : dictionary) st.insert(x);

        vector<int> dp(n,-1);

        return solve(0,s,dp) == 0;
    }
};
