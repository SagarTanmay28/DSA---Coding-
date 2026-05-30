In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]


class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> ans(n,0);

        unordered_map<int,int> mp;
        for(auto &x : barcodes) mp[x]++;

        priority_queue<pi> pq;
        for(auto &x : mp) pq.push({x.second,x.first});

        int i = 0;
        while(pq.size() != 0){
            int freq = pq.top().first;
            int val = pq.top().second;
            pq.pop();

            while(freq--){
                if(i >= n) i=1;
                ans[i] = val;
                i += 2;
            }
           
        }
        return ans;
        
    }
};
