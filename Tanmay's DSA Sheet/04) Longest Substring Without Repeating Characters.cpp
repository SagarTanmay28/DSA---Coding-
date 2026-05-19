class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int ans = 0;
        unordered_map<char,int> mp;

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            mp[s[j]]++;

            while(j - i + 1 != mp.size()){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};
