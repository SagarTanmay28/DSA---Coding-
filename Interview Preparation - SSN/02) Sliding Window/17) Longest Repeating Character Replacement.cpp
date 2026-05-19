You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int maxFreq = 0;

        int i = 0;
        int j = 0;
        vector<int> mp(26);
        // Sliding Window 
        while(j < n){
             mp[s[j] - 'A']++;
             maxFreq = max(maxFreq,mp[s[j] - 'A']);

             // len - maxFreq <= k hona chaiye 
             int len = j - i + 1;
             if(len - maxFreq > k){
                mp[s[i] - 'A']--;
                i++;
             }

             if(len - maxFreq <= k) maxLen = max(maxLen,len);
             j++;
        }

        return maxLen;
    }
};
