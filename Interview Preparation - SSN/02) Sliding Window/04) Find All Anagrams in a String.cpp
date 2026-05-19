Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
      int n = s.size();
      int m = p.size();

      unordered_map<char,int> mp;
      for(char ch : p) mp[ch]++;

      vector<int> ans;

      int i = 0;
      int j = 0;
      unordered_map<char,int> window;
      // Sliding Window 
      while(j < n){
          window[s[j]]++;

          while(j-i+1 > m){
              window[s[i]]--;
              if(window[s[i]] == 0) window.erase(s[i]);
              i++;
          }

          if(j - i + 1 == m && window == mp) ans.push_back(i);
          j++;
      }

      return ans;
  }
};
