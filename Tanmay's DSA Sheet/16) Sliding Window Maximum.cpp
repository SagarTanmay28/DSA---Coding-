class Solution {
public:
    typedef pair<int,int> p;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        priority_queue<p> pq;
       

        for (int i = 0; i < k; ++i) {
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
    

        for(int i=k;i<n;i++){
            pq.push({nums[i],i});

            while(pq.top().second <= i - k){
                  pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;


        
    }
};
