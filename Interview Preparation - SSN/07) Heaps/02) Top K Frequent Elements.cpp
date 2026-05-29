class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto &x : nums) mp[x]++;

        priority_queue< pi, vector<pi>, greater<pi> > pq;

        for(auto&x : mp){
            pq.push({x.second,x.first});
            if(pq.size() > k) pq.pop();
        } 

        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};
