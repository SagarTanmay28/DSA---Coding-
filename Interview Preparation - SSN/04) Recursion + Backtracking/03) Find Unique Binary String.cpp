class Solution {
public:
    void all(string s, int n, vector<string>& v){
        if(s.size() == n){
            v.push_back(s);
            return;
        }
        all(s + '0',n,v);
        all(s + '1',n,v);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums[0].size();
        unordered_set<string> st(nums.begin(),nums.end());

        vector<string> v;

        all("",n,v);

        for(int i=0;i<v.size();i++){
            if(st.find(v[i]) == st.end()) return v[i];
        }

        return "";
    }
};

// Optimal 

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
         int n = nums.size();
        string ans = "";
        for(int i = 0; i < n; ++i){
            ans += nums[i][i] == '0' ? '1' : '0';  // Flip the ith bit
        }
        return ans;
    }
};
