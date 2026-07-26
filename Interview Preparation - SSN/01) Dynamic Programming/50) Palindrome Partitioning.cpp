class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int idx, string &s, vector<string> &v, vector<vector<string>> &ans){
        if(idx == s.size()){
            ans.push_back(v);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                v.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, v, ans);
                v.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;

        solve(0, s, v, ans);
        return ans;
    }
};
