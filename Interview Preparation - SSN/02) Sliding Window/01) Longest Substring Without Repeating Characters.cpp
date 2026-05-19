Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> mp;

        int maxi = INT_MIN;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            mp[s[j]]++;

            while(mp.size() != (j - i + 1)){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return (maxi == INT_MIN) ? 0 : maxi;
    }
};
