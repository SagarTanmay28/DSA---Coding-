There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

2 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst



class Solution {
public:
    typedef pair<int,pair<int,int>> pi;
    // { stops , {end , cost}}

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector< pair<int,int> >> adj(n);
        // Adjacency Matrix Formed 
        for(int i=0;i<flights.size();i++){
            int start = flights[i][0];
            int end = flights[i][1];
            int cost = flights[i][2];

            adj[start].push_back({ end , cost });
        }

        priority_queue<pi,vector<pi>, greater<pi>> pq;
        vector<int> ans(n,INT_MAX);

        ans[src] = 0;
        pq.push({0,{src,0}});

        // Dijkshtras Algorithm 

        while(pq.size()){

            auto p = pq.top();
            pq.pop();

            int stops = p.first;
            int node = p.second.first;
            int cost = p.second.second;

            if(stops + 1 > k + 1) continue;

            for(auto x : adj[node]){
                
                int total_cost = cost + x.second;
                if(total_cost < ans[x.first]){
                    ans[x.first] = total_cost;
                    pq.push({stops + 1, {x.first,total_cost}});
                }
            }
        }

        return (ans[dst] != INT_MAX) ? ans[dst] : -1;

    }
};
