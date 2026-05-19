class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<n;i++){
            string lexo = strs[i];
            sort(lexo.begin(),lexo.end());

            mp[lexo].push_back(strs[i]);
        }

        for(auto x : mp) ans.push_back(x.second);

        return ans;
    }
};
