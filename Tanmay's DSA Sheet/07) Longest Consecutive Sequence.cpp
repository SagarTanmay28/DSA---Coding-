class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int> st(nums.begin(),nums.end());

        int longest = 1;
        
        for(int x : st){
            int count = 1;

            if(st.find(x-1) == st.end()){
                while(st.find(x+1) != st.end()){
                count++;
                x = x + 1;
                }
            }
            longest = max(longest,count);
            
        }
        
        return longest;
    }
};
