class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> mp;
        for(char ch : t) mp[ch]++;

        int min_len = INT_MAX;
        int start = -1;
        int count = t.size();

        int i = 0;
        int j = 0;
        // Sliding Window 
        while(j < n){
            if(mp[s[j]] > 0) count--;
            mp[s[j]]--;

            while(count == 0){
                if(min_len > j - i + 1){
                    min_len = j - i + 1;
                    start = i;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0) count++;
                i++;
                
            }

            j++;  
            
        }

        return (start == -1) ? "" : s.substr(start,min_len);
        
    }
};
