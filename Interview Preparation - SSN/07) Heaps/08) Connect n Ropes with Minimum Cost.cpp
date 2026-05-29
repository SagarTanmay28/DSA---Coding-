Given an array arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation:  Minimum cost to connect all ropes into a single rope is 
Connect ropes 2 and 3 - [4, 5, 6], cost = 5
Connect ropes 4 and 5 - [9, 6], cost = 9
Connect ropes 9 and 6 - [15], cost = 15
Total cost = 5 + 9 + 15 = 29 


class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int x : arr) pq.push(x);
        
        int cost = 0;
        
        while(pq.size() > 1){
            
            int x = pq.top();
            pq.pop();
            
            int y = pq.top();
            pq.pop();
            
            int sum = x + y;
            
            cost += sum;
            
            // push new combined rope
            pq.push(sum);
        }
        
        return cost;
        
    }
};
