Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.


class Solution {
public:
    typedef pair<int,char> p;
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char,int> mp;
        string ans = "";

        for(char ch : s) mp[ch]++;

        priority_queue<p> pq;

        for(auto &x : mp) pq.push({x.second,x.first});

        while(pq.size()){
            int freq = pq.top().first;
            char ch = pq.top().second;

            ans += string(freq,ch);
            pq.pop();
        }

        return ans;
        
    }
};
