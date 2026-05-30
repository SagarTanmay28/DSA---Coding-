You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

// Crazy Solution - Dry Run 

class Solution {
public:
    typedef pair<int,pair<int,int>> pi;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pi, vector<pi>, greater<pi>> pq;

        // initially push first element of nums2 with every nums1[i]
        for(int i = 0; i < min(n1,k); i++){
            pq.push({nums1[i] + nums2[0], {i,0}});
        }

        vector<vector<int>> ans;

        while(k-- && !pq.empty()){

            auto top = pq.top();
            pq.pop();

            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            // push next element from nums2
            if(j + 1 < n2){
                pq.push({nums1[i] + nums2[j+1], {i,j+1}});
            }
        }

        return ans;
    }
};

// Simple and Clean 

class Solution {
public: // Very IMP Break Condition here 
    typedef pair<int,vector<int> > pi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pi> pq;
      
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
               int x = nums1[i];
               int y = nums2[j];
               if(pq.size() < k ) pq.push({x+y,{x,y}});
               else if(pq.top().first > x + y){
                pq.pop();
                pq.push({x+y,{x,y}});
               }
               else break; // VIMP 
            }  
        }
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};
