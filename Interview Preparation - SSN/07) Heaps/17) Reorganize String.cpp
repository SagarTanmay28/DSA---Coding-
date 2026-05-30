Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""


class Solution {
public:
    typedef pair<int,char> pi;
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]++;

        priority_queue<pi> pq;
        for(auto &x : mp){
            if(x.second > (n+1)/2) return "";
            pq.push({x.second,x.first});
        }

        string ans(n,'0');
        
        int i = 0;
        while(pq.size() != 0){
            int freq = pq.top().first;
            char val = pq.top().second;
            pq.pop();

            while(freq--){
                if(i >= n) i = 1;
                ans[i] = val;
                i += 2;
            }
            
        }

        for(int j=0;j<n-1;j++){
            if(ans[j]==ans[j+1]) return "";
        }

        return ans;
        
    }
};
